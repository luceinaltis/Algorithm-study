#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

vector<string> mp;
int visited[1000][1000][2];
int n, m;
int ans = 987654321;

// 위, 오른, 아래, 왼
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

void bfs()
{
    /*
     *  first : 거리
     *  second : 위치
     *  third : 벽부시기 가능한 횟수
     */
    queue<tuple<int, pair<int, int>, int>> que;

    memset(visited, 0, sizeof(visited));

    que.push(make_tuple(1, pair<int, int>(0, 0), 1));
    visited[0][0][1] = 1;

    // 비지 않을 때 까지
    while (!que.empty())
    {
        tuple<int, pair<int, int>, int> tmp = que.front();
        que.pop();

        int dist = get<0>(tmp);
        pair<int, int> pos = get<1>(tmp);
        int canDelWall = get<2>(tmp);

        if (pos.first == n - 1 && pos.second == m - 1)
        {
            ans = dist;
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nextX = pos.first + dirX[i];
            int nextY = pos.second + dirY[i];

            if (nextX < 0 || n <= nextX)
                continue;
            if (nextY < 0 || m <= nextY)
                continue;

            if (!visited[nextX][nextY][canDelWall] && mp[nextX][nextY] == '0')
            {
                que.push(make_tuple(dist + 1, pair<int, int>(nextX, nextY), canDelWall));
                visited[nextX][nextY][canDelWall] = 1;
            }

            if (canDelWall && !visited[nextX][nextY][canDelWall] && mp[nextX][nextY] == '1')
            {
                que.push(make_tuple(dist + 1, pair<int, int>(nextX, nextY), canDelWall - 1));
                visited[nextX][nextY][canDelWall] = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    mp.assign(n, "");

    for (int i = 0; i < n; ++i)
    {
        cin >> mp[i];
    }

    bfs();

    if (ans == 987654321)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}