#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
double s, v;

// rat coordinates
vector<pair<double, double>> rats;
// tunnels coordinates
vector<pair<double, double>> tunnels;

vector<vector<int>> adj;
vector<int> aMatch, bMatch;
vector<int> visited;

bool dfs(int a)
{
  if (visited[a])
    return false;

  visited[a] = 1;

  for (int b = 0; b < m; ++b)
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

double distance(const pair<double, double> &a, const pair<double, double> &b)
{
  double width = abs(a.second - b.second);
  double height = abs(a.first - b.first);
  return sqrt(width * width + height * height);
}

void preprocess()
{
  for (int ratIdx = 0; ratIdx < n; ++ratIdx)
  {
    for (int tunnelIdx = 0; tunnelIdx < m; ++tunnelIdx)
    {
      if (distance(rats[ratIdx], tunnels[tunnelIdx]) <= s * v)
      {
        adj[ratIdx][tunnelIdx] = 1;
      }
    }
  }
}

int main()
{
  cin >> n >> m >> s >> v;

  adj.assign(n, vector<int>(m, 0));
  visited.assign(n, 0);
  aMatch.assign(n, -1);
  bMatch.assign(m, -1);

  for (int i = 0; i < n; ++i)
  {
    double x, y;
    cin >> x >> y;
    rats.push_back({x, y});
  }

  for (int i = 0; i < m; ++i)
  {
    double x, y;
    cin >> x >> y;
    tunnels.push_back({x, y});
  }

  preprocess();

  int size = 0;
  for (int i = 0; i < n; ++i)
  {
    visited.assign(n, 0);

    if (dfs(i))
    {
      size += 1;
    }
  }

  cout << n - size << '\n';

  return 0;
}