#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

int n;
pair<int, int> pos[100];
double dist[100][100];
int visited[100];

double calculateDistance(pair<int, int> &a, pair<int, int> &b)
{
    double xDist = a.first - b.first;
    double yDist = a.second - b.second;

    double dist = sqrt(xDist * xDist + yDist * yDist);

    return dist;
}

// MST를 찾아 총 거리를 반환해주자.
double primAlgorithm()
{
    double ret = 0;
    // 간선 크기, 시작 정점, 끝 정점
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;

    // 초기화
    // 0번 정점을 넣자
    for (int i = 1; i < n; ++i)
    {
        pq.push(make_tuple(dist[0][i], 0, i));
    }
    visited[0] = 1;

    while (!pq.empty())
    {
        // 가장 최소 거리의 간선을 꺼내자
        double tmpDist = get<0>(pq.top());
        int from = get<1>(pq.top());
        int to = get<2>(pq.top());
        pq.pop();

        // 최소 거리의 간선이 집합 안의 간선이라면 건너뛰자.
        if (visited[to] != 0)
        {
            continue;
        }

        // 뽑힌 간선의 길이를 ret에 더하자
        visited[to] = 1;
        ret += tmpDist;

        for (int adj = 0; adj < n; ++adj)
        {
            // 이 간선이 집합에 포함되지 않았다면
            if (visited[adj] == 0 && adj != to)
            {
                pq.push(make_tuple(dist[to][adj], to, adj));
            }
        }
    }
    return ret;
}

int main()
{

    cin >> n;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; ++i)
    {
        double x, y;

        cin >> x >> y;

        pos[i] = {x, y};
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dist[i][j] = calculateDistance(pos[i], pos[j]);
        }
    }

    cout << primAlgorithm() << '\n';

    return 0;
}