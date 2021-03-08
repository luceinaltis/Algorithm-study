#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<int>> adj;
int visited[101];
int n;

vector<vector<int>> vertexes;
vector<int> isCircle;

int dfs(int tmp, int realStart)
{
    visited[tmp] = 1;
    vertexes[realStart].push_back(tmp);

    for (int i = 0; i < adj[tmp].size(); ++i)
    {
        int nextV = adj[tmp][i];

        if (visited[nextV] == 0)
        {
            return dfs(nextV, realStart);
        }
        else if (visited[nextV] == 1 && nextV == realStart)
        {
            isCircle[realStart] = 1;
            return 1;
        }
    }

    return 0;
}

void printAllVertex()
{
    vertexes.assign(n + 1, vector<int>());
    isCircle.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (isCircle[i])
        {
            ans += 1;
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; ++i)
    {
        if (isCircle[i])
        {
            cout << i << '\n';
        }
    }
}

int main()
{
    cin >> n;

    adj.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; ++i)
    {
        int adjVertex;

        cin >> adjVertex;

        adj[i].push_back(adjVertex);
    }

    printAllVertex();

    return 0;
}