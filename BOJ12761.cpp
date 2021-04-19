#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a, b, n, m;
int visited[100001];

int bfs()
{
    int out = 0;
    int ret = 0;
    // first : 현재 위치
    queue<int> que;

    // 초기화
    que.push(n);

    while (!que.empty() && out == 0)
    {
        int k = que.size();
        ret += 1;

        for (int i = 0; i < k; ++i)
        {
            int tmp = que.front();
            que.pop();

            if (tmp == m)
            {
                out = 1;
                break;
            }

            if (visited[tmp])
            {
                continue;
            }
            visited[tmp] = 1;

            for (int j = 0; j < 8; ++j)
            {
                int next;
                switch (j)
                {
                case 0:
                    next = tmp - 1;
                    break;
                case 1:
                    next = tmp + 1;
                    break;
                case 2:
                    next = tmp - a;
                    break;
                case 3:
                    next = tmp + a;
                    break;
                case 4:
                    next = tmp - b;
                    break;
                case 5:
                    next = tmp + b;
                    break;
                case 6:
                    next = tmp * a;
                    break;
                case 7:
                    next = tmp * b;
                    break;
                }

                if (next < 0 || 100000 < next)
                    continue;

                if (visited[next] == 0)
                {
                    que.push(next);
                }
            }
        }
    }
    return ret - 1;
}

int main()
{
    memset(visited, 0, sizeof(visited));

    cin >> a >> b >> n >> m;

    cout << bfs() << '\n';

    return 0;
}