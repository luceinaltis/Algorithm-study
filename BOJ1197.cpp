#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int parent[10001], level[10001];
vector<tuple<int, int, int>> arr;

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

    if (level[u] < level[v])
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
    int v, e;

    cin >> v >> e;

    for (int i = 1; i <= v; ++i)
    {
        parent[i] = i;
        level[i] = 1;
    }

    for (int i = 0; i < e; ++i)
    {
        int a, b, c;

        cin >> a >> b >> c;

        arr.push_back(make_tuple(c, a, b));
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        int a, b, c;

        c = get<0>(arr[i]);
        a = get<1>(arr[i]);
        b = get<2>(arr[i]);

        a = find(a);
        b = find(b);

        if (a == b)
        {
            continue;
        }

        union_(a, b);

        ans += c;
    }

    cout << ans << '\n';

    return 0;
}