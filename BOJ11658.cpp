#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<ll>> origin;
vector<vector<ll>> bit2d;

void update(int x, int y, ll value)
{
  ll diff = value - origin[x][y];
  origin[x][y] = value;
  while (x <= n)
  {
    int temp_y = y;
    while (temp_y <= n)
    {
      bit2d[x][temp_y] += diff;
      temp_y += (temp_y & -temp_y);
    }
    x += (x & -x);
  }
}

ll query(int x, int y)
{
  ll ret = 0;
  while (x >= 1)
  {
    int temp_y = y;
    while (temp_y >= 1)
    {
      ret += bit2d[x][temp_y];
      temp_y -= (temp_y & -temp_y);
    }
    x -= (x & -x);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  origin.assign(n + 1, vector<ll>(n + 1, 0));
  bit2d.assign(n + 1, vector<ll>(n + 1, 0));
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      ll value;
      cin >> value;
      update(i, j, value);
    }
  }

  for (int i = 0; i < m; ++i)
  {
    int w;

    cin >> w;
    switch (w)
    {
    case 0:
    {
      int x, y, c;
      cin >> x >> y >> c;
      update(x, y, c);
      break;
    }
    case 1:
    {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      ll ans = query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
      cout << ans << '\n';
      break;
    }
    default:
      break;
    }
  }

  return 0;
}