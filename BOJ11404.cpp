#include <iostream>
#define INF 987654321
using namespace std;

int n, m;
// first : 연결된 정점, second : 거리
int adj[101][101];

void floydWarshall()
{
    for (int mid = 1; mid <= n; ++mid)
    {
        for (int start = 1; start <= n; ++start)
        {
            for (int end = 1; end <= n; ++end)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0; j < 101; ++j)
        {
            adj[i][j] = INF;
            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;

        cin >> a >> b >> c;

        adj[a][b] = adj[a][b] < c ? adj[a][b] : c;
    }

    floydWarshall();

    for (int start = 1; start <= n; ++start)
    {
        for (int end = 1; end <= n; ++end)
        {
            if (adj[start][end] != INF)
            {
                cout << adj[start][end] << ' ';
            }
            else
            {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}