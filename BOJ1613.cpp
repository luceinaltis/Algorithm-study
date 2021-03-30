#include <iostream>
#include <cstring>
using namespace std;

int adj[401][401];
int n, k;
int s;

/*
 * 플로이드 와샬 알고리즘
 * 
 * 최단 경로를 찾는 알고리즘
 * 시간 복잡도 : O(V^3)
 * 지나는 경로의 중간 정점을 모든 시작 정점, 끝 정점의 경우를 계산하는 방법
 * 모든 중간 정점을 계산하고나면 최단 경로가 도출된다.
 */
void floydWarshall()
{
    for (int mid = 1; mid <= n; ++mid)
    {
        for (int start = 1; start <= n; ++start)
        {
            for (int end = 1; end <= n; ++end)
            {
                if (adj[start][mid] == -1 && adj[mid][end] == -1)
                {
                    adj[start][end] = -1;
                }
                else if (adj[start][mid] == 1 && adj[mid][end] == 1)
                {
                    adj[start][end] = 1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(adj, 0, sizeof(adj));

    cin >> n >> k;

    for (int i = 1; i <= k; ++i)
    {
        int a, b;

        cin >> a >> b;

        adj[a][b] = -1;
        adj[b][a] = 1;
    }

    floydWarshall();

    cin >> s;

    for (int i = 0; i < s; ++i)
    {
        int a, b;

        cin >> a >> b;

        cout << adj[a][b] << '\n';
    }

    return 0;
}