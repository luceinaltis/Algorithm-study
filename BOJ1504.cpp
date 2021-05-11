#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef long long ll;

int n, e;
// first: 정점, second: 거리
vector<vector<pair<int, int>>> adj;
vector<int> visited;
vector<int> minDist;

struct compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second > b.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// start에서 end까지의 최단 경로의 길이를 반환하다.
// 경로가 없을 때 -1을 반환한다.
int dijkstra(int start, int end)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    visited.assign(n + 1, 0);
    minDist.assign(n + 1, INF);

    // first: 정점, second: 거리
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    // 초기화
    visited[start] = 1;
    minDist[start] = 0;
    for (int i = 0; i < adj[start].size(); ++i)
    {
        pair<int, int> edge = adj[start][i];
        int adjVertex = edge.first;
        int dist = edge.second;

        minDist[adjVertex] = dist;
        pq.push({adjVertex, dist});
    }

    while (!pq.empty())
    {
        pair<int, int> tmp = pq.top();
        int tmpVertex = tmp.first;
        int tmpDist = tmp.second;
        pq.pop();

        if (visited[tmpVertex])
            continue;
        visited[tmpVertex] = 1;

        for (int i = 0; i < adj[tmpVertex].size(); ++i)
        {
            int nextVertex = adj[tmpVertex][i].first;
            int nextVertexDist = adj[tmpVertex][i].second;

            if (minDist[nextVertex] > minDist[tmpVertex] + nextVertexDist)
            {
                minDist[nextVertex] = minDist[tmpVertex] + nextVertexDist;
                pq.push({nextVertex, minDist[nextVertex]});
            }
        }
    }

    return minDist[end];
}

int main()
{
    cin >> n >> e;

    adj.assign(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < e; ++i)
    {
        int a, b, c;

        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    ll startToV1MinDist = dijkstra(1, v1);
    ll startToV2MinDist = dijkstra(1, v2);
    ll endToV1MinDist = dijkstra(n, v1);
    ll endToV2MinDist = dijkstra(n, v2);
    ll v1ToV2MinDist = dijkstra(v1, v2);

    ll ans = INF;
    ans = min(ans, startToV1MinDist + endToV1MinDist + v1ToV2MinDist * 2);
    ans = min(ans, startToV2MinDist + endToV2MinDist + v1ToV2MinDist * 2);
    ans = min(ans, startToV1MinDist + endToV2MinDist + v1ToV2MinDist);
    ans = min(ans, startToV2MinDist + endToV1MinDist + v1ToV2MinDist);
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