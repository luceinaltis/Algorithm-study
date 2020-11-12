#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> canHack;

int n, m;

// here에서 시작해서 bfs로 모든 점을 탐색하자.
// 해킹 가능한 수를 반환하자.
// O(1000000000)
void bfs(int start)
{
    visited.assign(n + 1, 0);
    // 방문하지 않았다고 하자
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();

        for (int next = 0; next < adj[here].size(); ++next)
        {
            int nextVertex = adj[here][next];
            if (!visited[nextVertex])
            {
                visited[nextVertex] = 1;
                canHack[nextVertex] += 1;
                q.push(nextVertex);
            }
        }
    }
}

void calculate()
{

    visited.assign(n + 1, 0);

    int maximum = 0;
    for (int i = 1; i <= n; ++i)
    {
        bfs(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        maximum = max(maximum, canHack[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (maximum == canHack[i])
            cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // 컴퓨터의 번호는 1부터 시작한다.
    adj.assign(n + 1, vector<int>());
    canHack.assign(n + 1, 1);

    for (int i = 0; i < m; ++i)
    {
        int from, to;

        cin >> from >> to;

        adj[from].push_back(to);
    }

    calculate();

    return 0;
}