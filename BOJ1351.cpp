#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

map<ll, ll> cache;
ll n, p, q;

ll dp(ll n)
{
    // 기저사례
    if (n == 0)
        return 1;

    // 메모이제이션
    ll &ret = cache[n];
    if (ret != 0)
        return ret;

    ret = 0;
    ret += dp(n / p) + dp(n / q);
    return ret;
}

int main()
{
    cin >> n >> p >> q;

    cout << dp(n) << '\n';

    // cout << cache[1] << '\n';

    return 0;
}