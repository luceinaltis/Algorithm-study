#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
char isWomanUni[1001];
vector<vector<pair<int, int>>> adj;
int visited[1001];

int primAlgorithm()
{
    int ret = 0;
    int lineCnt = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int i = 0; i < adj[1].size(); ++i)
    {
        pq.push(make_tuple(adj[1][i].second, 1, adj[1][i].first));
    }
    visited[1] = 1;

    while (!pq.empty())
    {
        int tmpDist = get<0>(pq.top());
        int from = get<1>(pq.top());
        int to = get<2>(pq.top());
        pq.pop();

        if (visited[to] == 1 || isWomanUni[from] == isWomanUni[to])
        {
            continue;
        }

        visited[to] = 1;
        ret += tmpDist;
        lineCnt += 1;

        for (int i = 0; i < adj[to].size(); ++i)
        {
            int nextVertex = adj[to][i].first;
            int nextDist = adj[to][i].second;
            if (visited[nextVertex] == 0)
            {
                pq.push(make_tuple(nextDist, to, nextVertex));
            }
        }
    }

    if (lineCnt != n - 1)
    {
        return -1;
    }
    else
    {
        return ret;
    }
}

int main()
{
    cin >> n >> m;

    memset(isWomanUni, 0, sizeof(isWomanUni));
    memset(visited, 0, sizeof(visited));
    adj.assign(n + 1, vector<pair<int, int>>());

    for (int i = 1; i <= n; ++i)
    {
        cin >> isWomanUni[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v, d;

        cin >> u >> v >> d;

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    cout << primAlgorithm() << '\n';

    return 0;
}