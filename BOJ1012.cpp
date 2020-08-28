#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, 1, 0, -1};

int m, n, k;
int color = 0;

vector<vector<int>> map;
vector<vector<int>> visited;
vector<vector<int>> colored;


void dfs(int x, int y, int count, int color)
{
    colored[x][y] = color;
    for(int i = 0; i < 4; ++i)
    {
        int next_x = x + dir_x[i];
        int next_y = y + dir_y[i];

        if(next_x < 0 || next_x >= n) continue;
        if(next_y < 0 || next_y >= m) continue;

        if(map[next_x][next_y] == 1 && visited[next_x][next_y] == 0)
        {
            visited[next_x][next_y] = 1;
            dfs(next_x, next_y, !count, color);
        }
    }
}

void dfsAll()
{
    // 영역을 색칠한다.
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(map[i][j] == 1 && colored[i][j] == -1 && visited[i][j] == 0)
            {
                dfs(i, j, 0, color++);
            }
        }
    }

    cout << color << '\n';
}

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        cin >> m >> n >> k;

        map.assign(n, vector<int>(m, 0));
        visited.assign(n, vector<int>(m, 0));
        colored.assign(n, vector<int>(m, -1));

        color = 0;

        for(int i = 0; i < k; ++i)
        {
            int x, y;

            cin >> x >> y;

            map[y][x] = 1;
        }

        dfsAll();
    }

    return 0;
}