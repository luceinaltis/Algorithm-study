#include <iostream>
#include <algorithm>
using namespace std;

int parent[100001];
int level[100001];

int find(int u)
{
    if (parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

void union_(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (level[u] > level[v])
    {
        swap(u, v);
    }

    parent[v] = u;

    if (level[u] == level[v])
    {
        ++level[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 100001; ++i)
    {
        parent[i] = i;
        level[i] = 1;
    }

    int g, p;

    cin >> g >> p;

    for (int i = 0; i < p; ++i)
    {
        int gi;

        cin >> gi;

        int x = find(gi);

        if (x == 0)
            break;

        union_(x - 1, x);
    }

    int ans = 0;
    for (int i = 1; i <= g; ++i)
    {
        if (parent[i] != i)
        {
            ans += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}