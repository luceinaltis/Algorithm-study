#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> PA;

int n, d;

// (first: 지름길의 길이, second: 연결된 노드)
vector<vector<PA>> adj;
vector<int> visited;
vector<int> dist;

int dijkstra(int startNode)
{
    visited.assign(10001, 0);
    // 초기화
    // (거리, 현재 노드)
    priority_queue<PA, vector<PA>, greater<PA>> pq;
    dist[startNode] = 0;
    pq.push(PA(0, startNode));

    while (!pq.empty())
    {

        int hereDist = pq.top().first;
        int hereNode = pq.top().second;
        pq.pop();

        // 만약 방문한 점이었다면 건너뛰자
        if (visited[hereNode])
            continue;
        // 방문한 점으로 표시
        visited[hereNode] = 1;

        // 인접한 노드 탐색
        for (int next = 0; next < adj[hereNode].size(); ++next)
        {
            int nextNodeLength = adj[hereNode][next].second;
            int nextNode = adj[hereNode][next].first;

            // 거리가 줄어들었다면 기록하자
            if (dist[nextNode] > dist[hereNode] + nextNodeLength)
            {
                dist[nextNode] = dist[hereNode] + nextNodeLength;
                pq.push(PA(dist[nextNode], nextNode));
            }
        }
    }

    return dist[d];
}

int main()
{
    cin >> n >> d;

    // 0 ~ d까지 임의의 노드를 만들자
    adj.assign(10001, vector<PA>());
    dist.assign(10001, INF);

    for (int i = 0; i < n; ++i)
    {
        int start, end, length;

        cin >> start >> end >> length;

        adj[start].push_back(PA(end, length));
    }

    for (int i = 0; i < d; ++i)
    {
        adj[i].push_back(PA(i + 1, 1));
    }

    cout << dijkstra(0) << '\n';

    return 0;
}