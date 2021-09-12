#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> parent;
vector<int> _rank;
vector<pair<int, pair<int, int>>> adj;
vector<pair<int, int>> vertex;
int n, c;

int find(int);

void _union(int x, int y)
{
  x = find(x);
  y = find(y);

  if (x == y)
    return;

  if (_rank[x] < _rank[y])
  {
    swap(x, y);
  }

  parent[y] = x;
  if (_rank[x] == _rank[y])
  {
    _rank[x] += 1;
  }
}

int find(int x)
{
  return parent[x] != x ? parent[x] = find(parent[x]) : x;
}

int getDistance(int x, int y)
{
  int xDist = vertex[x].first - vertex[y].first;
  int yDist = vertex[x].second - vertex[y].second;
  return xDist * xDist + yDist * yDist;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> c;

  // initialization
  _rank.assign(n, 0);
  parent.assign(n, 0);
  for (int i = 0; i < n; ++i)
  {
    parent[i] = i;
  }
  vertex.assign(n, pair<int, int>());

  // input
  for (int i = 0; i < n; ++i)
  {
    int x, y;
    cin >> x >> y;

    vertex[i] = {x, y};
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      int distance = getDistance(i, j);

      if (distance < c)
        continue;

      adj.push_back({distance, {i, j}});
    }
  }

  sort(adj.begin(), adj.end());

  ll ans = 0;
  int adjSize = adj.size();
  for (int i = 0; i < adjSize; ++i)
  {
    int dist = adj[i].first;
    int x = adj[i].second.first;
    int y = adj[i].second.second;

    x = find(x);
    y = find(y);
    if (x == y)
      continue;

    _union(x, y);
    ans += dist;
  }

  for (int i = 1; i < n; ++i)
  {
    if (parent[i] != parent[i - 1])
    {
      cout << -1 << '\n';
      return 0;
    }
  }

  cout << ans << '\n';

  return 0;
}