#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int n, k;
int minCount[100001];
int minDist[100001];
int count = 0;

void bfs()
{
    queue<int> que;

    que.push(n);
    minDist[n] = 0;
    minCount[n] = 1;

    while (!que.empty())
    {
        int size = que.size();
        count += 1;

        for (int i = 0; i < size; ++i)
        {
            int tmp = que.front();
            que.pop();

            int next1 = tmp + 1;
            if (0 <= next1 && next1 <= 100000)
            {
                if (minDist[next1] >= count)
                {
                    if (minDist[next1] == INF)
                    {
                        que.push(next1);
                    }
                    minDist[next1] = count;
                    minCount[next1] += minCount[tmp];
                }
            }

            int next2 = tmp - 1;
            if (0 <= next2 && next2 <= 100000)
            {
                if (minDist[next2] >= count)
                {
                    if (minDist[next2] == INF)
                    {
                        que.push(next2);
                    }
                    minDist[next2] = count;
                    minCount[next2] += minCount[tmp];
                }
            }

            int next3 = tmp * 2;
            if (0 <= next3 && next3 <= 100000)
            {
                if (minDist[next3] >= count)
                {
                    if (minDist[next3] == INF)
                    {
                        que.push(next3);
                    }
                    minDist[next3] = count;
                    minCount[next3] += minCount[tmp];
                }
            }
        }

        // 최적화
        if (minDist[k] != INF)
        {
            return;
        }
    }
}

int main()
{
    for (int i = 0; i <= 100000; ++i)
    {
        minDist[i] = INF;
        minCount[i] = 0;
    }

    cin >> n >> k;

    bfs();

    cout << minDist[k] << '\n';
    cout << minCount[k] << '\n';

    return 0;
}