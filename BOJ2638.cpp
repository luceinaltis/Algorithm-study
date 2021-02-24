#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> mp;
vector<vector<int>> visited;

// 위, 오른, 아래, 왼
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visited[x][y] += 1;

    // 경우의 수
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (nextX < 0 || n <= nextX)
            continue;
        if (nextY < 0 || m <= nextY)
            continue;

        if (visited[nextX][nextY] == 0 && mp[nextX][nextY] == 0)
        {
            dfs(nextX, nextY);
        }

        if (mp[nextX][nextY] == 1)
        {
            visited[nextX][nextY] += 1;
        }
    }
}

// 치즈를 공기에 노출시킨다.
// 녹을 치즈가 있다면 녹이고 1을 반환하자.
// 녹을 치즈가 없다면 0을 반환한다.
int expose()
{
    int ret = 0;
    visited.assign(n, vector<int>(m, 0));

    dfs(0, 0);

    // 노출된 치즈를 감별해서 지우자
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j] >= 2 && mp[i][j] == 1)
            {
                mp[i][j] = 0;
                ret = 1;
            }
        }
    }

    return ret;
}

int main()
{

    cin >> n >> m;

    mp.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mp[i][j];
        }
    }

    int ans = 0;
    while (expose())
    {
        ans += 1;
    }

    cout << ans << '\n';

    return 0;
}