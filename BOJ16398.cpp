#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int n;
// 행성번호 : 0 ~ n-1
int adj[1000][1000];
int visited[1000];

/*
 * 프림 알고리즘
 * 그래프에서 MST의 값을 찾아 반환해주자.
 */
long long primAlgorithm()
{
    long long ret = 0;
    // first : 거리, second : 시작 정점, to : 종료 정점
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    // 초기화
    for (int i = 0; i < n; ++i)
    {
        pq.push(make_tuple(adj[0][i], 0, i));
    }
    visited[0] = 1;

    while (!pq.empty())
    {
        int tmpDist = get<0>(pq.top());
        int from = get<1>(pq.top());
        int to = get<2>(pq.top());
        pq.pop();

        if (visited[to])
        {
            continue;
        }
        visited[to] = 1;
        ret += tmpDist;

        // to에서 연결된 다음 정점을 찾자
        for (int nextV = 0; nextV < n; ++nextV)
        {
            // 방문하지 않은 정점에 들가자
            if (visited[nextV] == 0 && nextV != to)
            {
                pq.push(make_tuple(adj[to][nextV], to, nextV));
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(visited, 0, sizeof(visited));

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];
        }
    }

    cout << primAlgorithm() << '\n';

    return 0;
}