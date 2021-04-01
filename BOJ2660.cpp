#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int adj[50][50];
int score[50];
int visited[50];
int n;

// 현재 tmp의 점수를 반환한다.
int bfs(int tmp)
{
    memset(visited, 0, sizeof(visited));

    int ret = -1;
    queue<int> que;

    // 초기화
    que.push(tmp);

    while (!que.empty())
    {
        int k = que.size();
        ret++;

        for (int j = 0; j < k; ++j)
        {
            int tmpVertex = que.front();
            que.pop();

            if (visited[tmpVertex])
            {
                continue;
            }
            visited[tmpVertex] = 1;

            for (int i = 0; i < n; ++i)
            {
                int nextVertex = i;

                // 인접한 상태이고 방문하지 않았다면
                if (adj[tmpVertex][nextVertex] && visited[nextVertex] == 0)
                {
                    que.push(nextVertex);
                }
            }
        }
    }

    return ret;
}

int main()
{

    memset(adj, 0, sizeof(adj));
    memset(score, 0, sizeof(score));

    cin >> n;

    int a = 0, b = 0;

    while (a != -1 && b != -1)
    {
        cin >> a >> b;

        if (a == -1 && b == -1)
            continue;

        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        score[i] = bfs(i);
    }

    int minScore = score[0];
    for (int i = 0; i < n; ++i)
    {
        if (minScore > score[i])
        {
            minScore = score[i];
        }
    }

    int candidateCount = 0;
    for (int i = 0; i < n; ++i)
    {
        if (score[i] == minScore)
        {
            candidateCount++;
        }
    }

    cout << minScore << ' ' << candidateCount << '\n';
    for (int i = 0; i < n; ++i)
    {
        if (score[i] == minScore)
        {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';

    return 0;
}