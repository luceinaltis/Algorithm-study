#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<vector<int>> adj;
vector<int> visited;
int count = 0;

void dfs(int tmp, bool reverse = false)
{
    visited[tmp] = 1;
    count += 1;

    // 순방향이라면 정상적으로 탐색하자
    if (reverse == false)
    {
        for (int nextIdx = 1; nextIdx <= n; ++nextIdx)
        {
            if (adj[tmp][nextIdx] == 1 && visited[nextIdx] == 0)
            {
                dfs(nextIdx, reverse);
            }
        }
    }
    else
    {
        // 역방향으로 탐색하자
        for (int nextIdx = 1; nextIdx <= n; ++nextIdx)
        {
            if (adj[nextIdx][tmp] == 1 && visited[nextIdx] == 0)
            {
                dfs(nextIdx, reverse);
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    adj.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i)
    {
        int a, b;

        cin >> a >> b;

        adj[a][b] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        visited.assign(n + 1, 0);

        dfs(i);
        dfs(i, true);
        if (count == n + 1)
        {
            ans += 1;
        }

        count = 0;
    }

    cout << ans << '\n';

    return 0;
}