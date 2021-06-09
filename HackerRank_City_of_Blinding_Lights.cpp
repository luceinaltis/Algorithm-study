#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

typedef vector<vector<int>> ADJ;

ADJ floydWarshall(const ADJ &adj, int n)
{
    ADJ minDist;
    minDist.assign(adj.begin(), adj.end());

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (minDist[i][j] == -1)
            {
                minDist[i][j] = INF;
            }
        }
    }

    for (int mid = 1; mid <= n; ++mid)
    {
        for (int start = 1; start <= n; ++start)
        {
            for (int end = 1; end <= n; ++end)
            {
                if (minDist[start][end] > minDist[start][mid] + minDist[mid][end])
                {
                    minDist[start][end] = minDist[start][mid] + minDist[mid][end];
                }
            }
        }
    }

    return minDist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m;

    ADJ adj(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; ++i)
    {
        adj[i][i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;

        cin >> u >> v >> w;

        adj[u][v] = w;
    }

    ADJ minDist = floydWarshall(adj, n);

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        int from, to;
        cin >> from >> to;

        if (minDist[from][to] == INF)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << minDist[from][to] << endl;
        }
    }

    return 0;
}