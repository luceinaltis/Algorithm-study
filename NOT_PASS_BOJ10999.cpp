#include <iostream>
#include <cstring>
#define MAX (1 << 20)
using namespace std;

typedef long long ll;

ll fenwickTree[MAX];
ll arr[MAX];
int n, m, k;

// 펜윅 트리에서 구간 합을 계산한다.
// 구간 (1, i)의 합을 반환하자.
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

// 구간 (l, r)에 d를 더한다.
void update(int l, int r, ll d)
{
    for (int i = l; i <= r; ++i)
    {
        int tmpIdx = i;
        while (tmpIdx <= n)
        {
            fenwickTree[tmpIdx] += d;
            tmpIdx += (tmpIdx & -tmpIdx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        update(i, i, arr[i]);
    }

    for (int i = 0; i < m + k; ++i)
    {
        int a, b, c, d;
        cin >> a;

        switch (a)
        {
        case 1:
            cin >> b >> c >> d;
            update(b, c, d);
            break;
        case 2:
            cin >> b >> c;
            cout << query(b, c) << '\n';
            break;
        default:
            break;
        }
    }

    return 0;
}