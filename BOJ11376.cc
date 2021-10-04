#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<vector<int>> adj;
vector<int> bMatch;
vector<int> visited;

bool dfs(int a)
{
  if (visited[a])
    return false;
  visited[a] = 1;

  for (int b : adj[a])
  {
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
  cin >> n >> m;
  adj.assign(n + 1, vector<int>());
  bMatch.assign(m + 1, -1);
  for (int i = 1; i <= n; ++i)
  {
    int size;
    cin >> size;
    adj[i].assign(size, 0);
    for (int j = 0; j < size; ++j)
    {
      cin >> adj[i][j];
    }
  }

  int cnt = 0;
  for (int a = 1; a <= n; ++a)
  {
    for (int i = 0; i < 2; ++i)
    {
      visited.assign(n + 1, 0);
      if (dfs(a))
      {
        cnt += 1;
      }
    }
  }

  cout << cnt << '\n';

  return 0;
}