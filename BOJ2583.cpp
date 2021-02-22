#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int m, n, k;
vector<vector<int>> mp;
vector<vector<int>> visited;
vector<int> answer;

// 위, 오른, 아래, 왼
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};
int countSquare = 0;

void dfs(int x, int y)
{
    countSquare += 1;
    visited[x][y] = 1;

    // 경우의 수
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        // 범위 체크
        if (nextX < 0 || m <= nextX)
            continue;
        if (nextY < 0 || n <= nextY)
            continue;

        if (visited[nextX][nextY] == 0 && mp[nextX][nextY] == 0)
        {
            dfs(nextX, nextY);
        }
    }
}

int main()
{
    cin >> m >> n >> k;

    mp.assign(m, vector<int>(n, 0));
    visited.assign(m, vector<int>(n, 0));

    for (int i = 0; i < k; ++i)
    {
        int lx, ly;
        int rx, ry;

        cin >> lx >> ly >> rx >> ry;

        for (int x = m - ry; x < m - ly; ++x)
        {
            for (int y = lx; y < rx; ++y)
            {
                mp[x][y] = 1;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visited[i][j] == 0 && mp[i][j] == 0)
            {
                countSquare = 0;
                dfs(i, j);
                answer.push_back(countSquare);
            }
        }
    }

    sort(answer.begin(), answer.end(), less<int>());

    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}