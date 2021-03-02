#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int v, e;
int adj[401][401];

void floyd()
{
    for (int mid = 1; mid < 401; ++mid)
    {
        for (int start = 1; start < 401; ++start)
        {
            for (int end = 1; end < 401; ++end)
            {
                if (adj[start][end] > adj[start][mid] + adj[mid][end])
                {
                    adj[start][end] = adj[start][mid] + adj[mid][end];
                }
            }
        }
    }
}

int main()
{
    // 초기화
    for (int i = 0; i < 401; ++i)
    {
        for (int j = 0; j < 401; ++j)
        {
            adj[i][j] = INF;
        }
    }

    cin >> v >> e;

    for (int i = 0; i < e; ++i)
    {
        int a, b, c;

        cin >> a >> b >> c;

        adj[a][b] = c;
    }

    floyd();

    int ans = INF;
    for (int i = 1; i <= 400; ++i)
    {
        for (int j = 1; j <= 400; ++j)
        {
            ans = min(ans, adj[i][j] + adj[j][i]);
        }
    }

    if (ans == INF)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}