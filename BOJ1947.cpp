#include <iostream>
#include <cstring>
#define DIV 1000000000
using namespace std;

typedef long long ll;

ll cache[1000001];

ll dp(ll n)
{
    // 기저사례
    if (n == 2)
        return 1;
    if (n == 1)
        return 0;

    // 메모이제이션
    ll &ret = cache[n];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = 0;
    ret = (n - 1) * (dp(n - 2) + dp(n - 1));
    ret %= DIV;

    return ret;
}

int main()
{
    int n;
    memset(cache, -1, sizeof(cache));

    cin >> n;

    cout << dp(n) << '\n';

    return 0;
}