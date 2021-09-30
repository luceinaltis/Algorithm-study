#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<vector<int>> adj;
vector<int> aMatch, bMatch;
vector<int> visited;

bool dfs(int a)
{
  if (visited[a])
    return false;
  visited[a] = 1;

  for (int b = 1; b <= m; ++b)
  {
    if (adj[a][b])
    {
      if (bMatch[b] == -1 || dfs(bMatch[b]))
      {
        aMatch[a] = b;
        bMatch[b] = a;

        return true;
      }
    }
  }
  return false;
}

int main()
{

  cin >> n >> m;

  aMatch.assign(n + 1, -1);
  bMatch.assign(m + 1, -1);
  adj.assign(n + 1, vector<int>(m + 1, 0));
  for (int a = 1; a <= n; ++a)
  {
    int s;
    cin >> s;
    for (int j = 0; j < s; ++j)
    {
      int b;
      cin >> b;

      adj[a][b] = 1;
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; ++i)
  {
    visited.assign(n + 1, 0);
    if (dfs(i))
    {
      cnt += 1;
    }
  }

  cout << cnt << '\n';

  return 0;
}