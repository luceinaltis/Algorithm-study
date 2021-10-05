#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> bMatch;
vector<int> visited;

bool dfs(int a)
{
  if (visited[a])
    return false;
  visited[a] = 1;

  for (int i = 0; i < adj[a].size(); ++i)
  {
    int b = adj[a][i];
    if (bMatch[b] == -1 || dfs(bMatch[b]))
    {
      bMatch[b] = a;
      return true;
    }
  }
  return false;
}

int main()
{
  int n, m;

  cin >> n >> m;

  adj.assign(n + 1, vector<int>());
  bMatch.assign(n + 1, -1);
  for (int i = 1; i <= m; ++i)
  {
    int a, b;

    cin >> a >> b;
    adj[a].push_back(b);
  }

  int cnt = 0;
  for (int a = 1; a <= n; ++a)
  {
    visited.assign(n + 1, 0);
    if (dfs(a))
    {
      cnt += 1;
    }
  }

  cout << cnt << '\n';

  return 0;
}