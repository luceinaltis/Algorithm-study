#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int level[1000001];
int parent[1000001];

int find_(int u)
{
    if (parent[u] == u)
    {
        return u;
    }

    return parent[u] = find_(parent[u]);
}
void union_(int u, int v)
{
    u = find_(u);
    v = find_(v);

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

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        level[i] = 1;
    }

    for (int i = 0; i < m; ++i)
    {
        int cal, a, b;

        cin >> cal >> a >> b;

        switch (cal)
        {
        case 0:
            union_(a, b);
            break;
        case 1:
        {
            int u = find_(a);
            int v = find_(b);

            if (u == v)
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
            break;
        }
        default:
            break;
        }
    }

    return 0;
}