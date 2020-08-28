#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> space;
int visited[20][20];
int n, fishSize, eaten;

// 이차원 배열에서의 탐색을 편하게 해준다.
// 배워둔다면 두고두고 쓸 일이 있음!
// 위, 오른쪽, 아래, 왼쪽
int dir_x[4] = {-1, 0, 1, 0}; 
int dir_y[4] = {0, 1, 0, -1}; 

// 아기상어가 (x, y)의 좌표에서 다음 먹이까지 이동하는데 걸리는 시간을 반환하자.
// 만약, 아기상어의 먹잇감이 없다면 {-1, nextX, nextY}를 반환한다.
// 너비우선탐색을 통해 찾아가자.
// 반환형 : first = 걸리는 시간, second = 다음 x좌표, third = 다음 y좌표
tuple<int, int, int> findNextFeed(const int x, const int y)
{
    // first : x좌표, second : y좌표
    queue<pair<int, int>> que;

    int time = 0;
    // 큐 초기화
    memset(visited, 0, sizeof(visited));
    que.push(make_pair(x, y));
    visited[x][y] = 1;

    // 가장 위쪽, 가장 왼쪽 물고기를 찾기위한 배열
    vector<pair<int, int>> arr;

    while(!que.empty())
    {
        int tmpSize = que.size();
        time += 1;

        for(int i = 0; i < tmpSize; ++i)
        {
            pair<int, int> tmpLocation = que.front();
            que.pop();

            // 현재 좌표
            int tmpX = tmpLocation.first;
            int tmpY = tmpLocation.second;

            // 다음 큐에 넣을 만한 후보를 탐색
            for(int j = 0; j < 4; ++j)
            {
                int nextX = tmpX + dir_x[j];
                int nextY = tmpY + dir_y[j];

                // 범위를 벗어난다면 건너뛰자.
                if(nextX < 0 || nextX >= n) continue;
                if(nextY < 0 || nextY >= n) continue;

                if(!visited[nextX][nextY])
                {
                    // 먹을 수 있는 얘가 나타나면
                    if(space[nextX][nextY] < fishSize && space[nextX][nextY] > 0)
                    {
                        // 먹을 수 있는 물고기 후보에 추가하자.
                        arr.push_back(make_pair(nextX, nextY));
                    }
                    else if(space[nextX][nextY] > fishSize && space[nextX][nextY] > 0)
                    {
                        // 아기상어보다 크기가 큰 물고기의 공간은
                        // 지나갈 수 없다.
                        continue;
                    }

                    que.push(make_pair(nextX, nextY));
                    visited[nextX][nextY] = 1;
                }
            }
        }

        if(!arr.empty())
        {
            // 먹을 수 있는 후보에 뭔가 있다면
            // 가장 위쪽, 가장 왼쪽의 물고기를 먹자

            sort(arr.begin(), arr.end());
            int nextX = arr[0].first;
            int nextY = arr[0].second;

            // 한 마리 먹기
            eaten += 1;
            // 먹었으니 지도에서 없애자
            space[nextX][nextY] = 0;
            if(fishSize == eaten)
            {
                eaten = 0;
                fishSize += 1;
            }

            return {time, nextX, nextY};
        }
    }
    return {-1, 0, 0};
}

int solve()
{
    // 아기상어의 초기위치를 구하자.
    int x, y;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(space[i][j] == 9)
            {
                x = i;
                y = j;
                
                // 지우자..
                space[i][j] = 0;
            }
        }
    }

    int ans = 0;
    int time, nextX = x, nextY = y;
    while(true)
    {

        tuple<int, int, int> result = findNextFeed(nextX, nextY);

        // 아기상어의 위치를 그려주는 코드
        // for(int i = 0; i < n; ++i)
        // {
        //     for(int j = 0; j < n; ++j)
        //     {
        //         cout << space[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        time = get<0>(result);
        nextX = get<1>(result);
        nextY = get<2>(result);

        if(time == -1) break;

        ans += time;
    }
    return ans;
}

int main()
{
    cin >> n;

    space.assign(n, vector<int>(n, 0));
    fishSize = 2;
    eaten = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> space[i][j];
        }
    }

    cout << solve() << '\n';

    return 0;
}