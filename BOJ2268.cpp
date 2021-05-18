#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n, m;
ll fenwickTree[1000001];

// (1, i) 구간의 합 반환
ll sum(int i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += fenwickTree[i];
        i -= (i & -i);
    }
    return ret;
}

ll query(int l, int r)
{
    return sum(r) - sum(l - 1);
}

void update(int i, int val)
{
    ll diff = val - query(i, i);
    while (i <= n)
    {
        fenwickTree[i] += diff;
        i += (i & -i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // memset(fenwickTree, 0, sizeof(fenwickTree));

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a)
        {
        case 0:
            if (b > c)
            {
                int temp = b;
                b = c;
                c = temp;
            }
            cout << query(b, c) << '\n';
            break;
        case 1:
            update(b, c);
            break;
        }
    }

    return 0;
}