#include <iostream>
using namespace std;

typedef long long ll;

ll min(ll a, ll b)
{
    return a > b ? b : a;
}

int dfs(ll tmp, ll b)
{
    // 기저사례
    if (tmp > b)
        return 987654321;

    if (tmp == b)
        return 1;

    int ret = 987654321;
    ret = min(ret, dfs(tmp * 2, b) + 1);
    ret = min(ret, dfs(tmp * 10 + 1, b) + 1);
    return ret;
}

int main()
{
    ll a, b;

    cin >> a >> b;

    ll ans = dfs(a, b);
    if (ans == 987654321)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}