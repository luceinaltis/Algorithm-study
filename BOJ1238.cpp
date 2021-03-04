#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<pair<int, int>>> adj;
int visited[1001];
int dist[1001];

// return minimum distance from start vertex to end vertex.
int dijkstra(int start, int end)
{
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= 1000; ++i)
    {
        dist[i] = INF;
    }

    // first : 길이, second : 위치
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        pair<int, int> tmp = pq.top();
        pq.pop();

        int tmpDist = tmp.first;
        int tmpV = tmp.second;

        if (visited[tmpV])
            continue;
        visited[start] = 1;

        for (int i = 0; i < adj[tmpV].size(); ++i)
        {
            int nextV = adj[tmpV][i].first;
            int distance = adj[tmpV][i].second;
            // 이웃 중에서 길이가 더 짧아지는 구간이 있다면
            if (dist[nextV] > dist[tmpV] + distance)
            {
                dist[nextV] = dist[tmpV] + distance;
                pq.push({dist[nextV], nextV});
            }
        }
    }

    return dist[end];
}

int main()
{
    int n, m, x;

    cin >> n >> m >> x;

    adj.assign(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; ++i)
    {
        int a, b, t;

        cin >> a >> b >> t;

        adj[a].push_back({b, t});
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int dist = dijkstra(i, x) + dijkstra(x, i);
        ans = max(ans, dist);
    }

    cout << ans << '\n';

    return 0;
}