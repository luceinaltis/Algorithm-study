#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INFINITY 987654321
using namespace std;

// first: distance, second: from -> to
int n;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> adj;

// first: adjacent vertex, second: distance
vector<vector<pair<int, int>>> tmpAdj;

vector<int> parent;
vector<int> _rank;

int find(int x)
{
  return parent[x] != x ? parent[x] = find(parent[x]) : x;
}

void _union(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u == v)
    return;

  if (_rank[u] < _rank[v])
    swap(u, v);

  parent[v] = u;
  if (_rank[u] == _rank[v])
  {
    _rank[u] += 1;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  _rank.assign(n + 1, 1);
  parent.assign(n + 1, 0);
  for (int i = 1; i <= n; ++i)
  {
    parent[i] = i;
  }
  tmpAdj.assign(n + 1, vector<pair<int, int>>());

  for (int i = 1; i <= n; ++i)
  {
    for (int j = i + 1; j <= n; ++j)
    {
      int input;

      cin >> input;
      adj.push({input, {i, j}});
    }
  }

  while (!adj.empty())
  {
    int tmpDist = adj.top().first;
    int from = adj.top().second.first;
    int to = adj.top().second.second;
    adj.pop();

    if (find(from) != find(to))
    {
      _union(from, to);
      tmpAdj[from].push_back({to, tmpDist});
      tmpAdj[to].push_back({from, tmpDist});
    }
  }

  for (int i = 1; i <= n; ++i)
  {
    sort(tmpAdj[i].begin(), tmpAdj[i].end());
    cout << tmpAdj[i].size() << ' ';
    for (int j = 0; j < tmpAdj[i].size(); ++j)
    {
      cout << tmpAdj[i][j].first << ' ';
    }
    cout << '\n';
  }

  return 0;
}