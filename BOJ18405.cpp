#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// 위, 오른, 아래, 왼
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};
int n, k;
// 맵 0 ~ n-1
vector<vector<int>> mp;
vector<vector<int>> visited;

int bfs(int s, int x, int y)
{
    vector<queue<pair<int, int>>> ques;

    visited.assign(n, vector<int>(n, 0));
    ques.assign(k + 1, queue<pair<int, int>>());
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mp[i][j] != 0)
            {
                int virusNumber = mp[i][j];
                ques[virusNumber].push({i, j});
            }
        }
    }

    while (s--)
    {
        for (int virusNumber = 1; virusNumber <= k; ++virusNumber)
        {
            int size = ques[virusNumber].size();

            for (int i = 0; i < size; ++i)
            {
                int tmpX = ques[virusNumber].front().first;
                int tmpY = ques[virusNumber].front().second;
                ques[virusNumber].pop();

                visited[tmpX][tmpY] = 1;

                for (int j = 0; j < 4; ++j)
                {
                    int nextX = tmpX + dirX[j];
                    int nextY = tmpY + dirY[j];

                    // 범위체크
                    if (nextX < 0 || n <= nextX)
                        continue;
                    if (nextY < 0 || n <= nextY)
                        continue;

                    if (visited[nextX][nextY] == 0)
                    {
                        ques[virusNumber].push({nextX, nextY});
                        mp[nextX][nextY] = virusNumber;
                        visited[nextX][nextY] = 1;
                    }
                }
            }
        }
    }

    return mp[x - 1][y - 1];
}

int main()
{
    int s, x, y;
    cin >> n >> k;

    mp.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mp[i][j];
        }
    }

    cin >> s >> x >> y;

    cout << bfs(s, x, y) << '\n';

    return 0;
}