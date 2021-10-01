#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

vector<int> parent;
vector<int> _rank;
vector<int> groupSize;

struct vector2
{
public:
  int x, y;

  vector2(int _x, int _y)
  {
    x = _x;
    y = _y;
  }

  ll cross(vector2 other)
  {
    return this->x * other.y - other.x * this->y;
  }

  vector2 operator+(vector2 other) const
  {
    return vector2(this->x + other.x, this->y + other.y);
  }

  vector2 operator-(vector2 other) const
  {
    return vector2(this->x - other.x, this->y - other.y);
  }

  bool operator<(vector2 other) const
  {
    if (this->x == other.x)
    {
      return this->y < other.y;
    }
    return this->x < other.x;
  }
};

struct Linear
{
public:
  vector2 a, b;

  Linear(vector2 _a, vector2 _b) : a(_a), b(_b) {}
};

vector<Linear> linears;

// ret > 0, counter-clockwise
// ret < 0, clockwise
// ret == 0, in a line
ll ccw(const vector2 &A, const vector2 &B, const vector2 &C)
{
  long long op = A.x * B.y + B.x * C.y + C.x * A.y;
  op -= A.y * B.x + B.y * C.x + C.y * A.x;
  if (op > 0)
    return 1;
  else if (op < 0)
    return -1;
  else
    return 0;
}

bool isCross(Linear a, Linear b)
{
  int aCross = ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b);
  int bCross = ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b);

  // same line
  if (aCross == 0 && bCross == 0)
  {
    if (a.b < a.a)
      swap(a.a, a.b);
    if (b.b < b.a)
      swap(b.a, b.b);

    return !(a.b < b.a || b.b < a.a);
  }
  return aCross <= 0 && bCross <= 0;
}

int find(int u)
{
  return parent[u] == u ? u : parent[u] = find(parent[u]);
}

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

int main()
{
  int n;

  cin >> n;

  parent.assign(n, 0);
  groupSize.assign(n, 0);
  for (int i = 0; i < n; ++i)
  {
    parent[i] = i;
  }
  _rank.assign(n, 1);
  for (int i = 0; i < n; ++i)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector2 a = vector2(x1, y1);
    vector2 b = vector2(x2, y2);

    linears.push_back(Linear(a, b));
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = j + 1; j < n; ++j)
    {
      if (isCross(linears[i], linears[j]))
      {
        _union(i, j);
      }
    }
  }

  for (int i = 0; i < n; ++i)
  {
    groupSize[parent[i]] += 1;
  }

  int maxGroup = 0;
  int groupCnt = 0;
  for (int i = 0; i < n; ++i)
  {
    if (parent[i] == i)
      groupCnt++;

    if (groupSize[maxGroup] < groupSize[i])
    {
      maxGroup = i;
    }
  }

  cout << groupCnt << '\n';
  cout << groupSize[maxGroup] << '\n';

  return 0;
}