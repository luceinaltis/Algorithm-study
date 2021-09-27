#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> friends;
vector<vector<int>> enemies;

vector<int> parent;
vector<int> _rank;

int find(int);

void _union(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u == v)
    return;

  if (_rank[u] < _rank[v])
  {
    swap(u, v);
  }

  parent[v] = u;

  if (_rank[u] == _rank[v])
  {
    _rank[u] += 1;
  }
}

int find(int x)
{
  return parent[x] != x ? parent[x] = find(parent[x]) : x;
}

void process()
{
  // enemies
  for (int i = 1; i <= n; ++i)
  {
    int size = enemies[i].size();
    for (int j = 0; j + 1 < size; j++)
    {
      _union(enemies[i][j], enemies[i][j + 1]);
    }
  }

  // friends
  for (int i = 1; i <= n; ++i)
  {
    int size = friends[i].size();
    for (int j = 0; j < size; j++)
    {
      _union(i, friends[i][j]);
    }
  }
}

int main()
{
  cin >> n >> m;

  parent.assign(n + 1, 0);
  for (int i = 1; i <= n; ++i)
  {
    parent[i] = i;
  }
  _rank.assign(n + 1, 1);

  friends.assign(n + 1, vector<int>());
  enemies.assign(n + 1, vector<int>());
  for (int i = 0; i < m; ++i)
  {
    char relation;
    int gangsterA, gangsterB;

    cin >> relation >> gangsterA >> gangsterB;

    switch (relation)
    {
    case 'E':
      enemies[gangsterA].push_back(gangsterB);
      enemies[gangsterB].push_back(gangsterA);
      break;
    case 'F':
      friends[gangsterA].push_back(gangsterB);
      friends[gangsterB].push_back(gangsterA);
      break;
    default:
      break;
    }
  }

  process();

  int cnt = 0;
  for (int i = 1; i <= n; ++i)
  {
    if (parent[i] == i)
    {
      cnt += 1;
    }
  }
  cout << cnt << '\n';

  return 0;
}