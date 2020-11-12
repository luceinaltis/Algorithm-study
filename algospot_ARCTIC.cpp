#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int n;
double dist[101][101];
double posX[101];
double posY[101];

bool decision(double d)
{
    vector<bool> visited(n, false);
    queue<int> q;

    // 초기화
    // 시작은 0번 지점부터 시작하자!
    visited[0] = true;
    q.push(0);

    int seen = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        ++seen;
        for (int there = 0; there < n; ++there)
        {
            // 방문하지 않았고,
            // 거리가 d보다 같거나 작다면(연결되어 있다면)
            if (!visited[there] && dist[here][there] <= d)
            {
                visited[there] = true;
                q.push(there);
            }
        }
    }

    return seen == n;
}

double optimize()
{
    double lo = 0, hi = 1415.00;
    for (int it = 0; it < 100; ++it)
    {
        double mid = (lo + hi) / 2;
        if (decision(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    return hi;
}

int main()
{
    cout.precision(2);
    cout << fixed;

    int c;

    cin >> c;
    while (c--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> posX[i] >> posY[i];
        }

        // 실제 거리를 먼저 계산하자!
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                double width = abs(posY[i] - posY[j]);
                double height = abs(posX[i] - posX[j]);

                double tmpDist = sqrt(width * width + height * height);

                dist[i][j] = tmpDist;
            }
        }
        cout << optimize() << '\n';
    }

    return 0;
}