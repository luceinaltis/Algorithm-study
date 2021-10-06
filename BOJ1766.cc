#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> children;
vector<vector<int>> parents;

vector<int> visited;
vector<int> indegree;

vector<int> history;

int n, m;

void calculate()
{
  indegree.assign(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    indegree[i] = parents[i].size();

  vector<int> que;
  for (int i = 1; i <= n; ++i)
  {
    if (indegree[i] == 0)
    {
      que.push_back(i);
    }
  }

  while (!que.empty())
  {
    sort(que.begin(), que.end(), greater<int>());

        history.push_back(que.)
  }
}

int main()
{
  cin >> n >> m;
  children.assign(n + 1, vector<int>());
  parents.assign(n + 1, vector<int>());
  for (int i = 0; i < m; ++i)
  {
    int parent, child;

    cin >> child >> parent;
    children[parent].push_back(child);
    parents[child].push_back(parent);
  }

  for (auto a : history)
  {
    cout << a << ' ';
  }
  cout << '\n';

  return 0;
}