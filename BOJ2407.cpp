#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

ll cache[101][101];

ll dp(int n, int m)
{
    // 기저사례
    if (m == 0 || n == m)
        return 1;
    if (m == 1)
        return n;

    // 메모이제이션
    ll &ret = cache[n][m];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = 0;
    ret = dp(n - 1, m - 1) + dp(n - 1, m);
    return ret;
}

int main()
{
    int n, m;

    cin >> n >> m;

    memset(cache, -1, sizeof(cache));

    cout << dp(n, m) << '\n';

    return 0;
}