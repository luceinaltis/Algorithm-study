#include <iostream>
#include <cstring>
#define DIV 1000000000
using namespace std;

typedef long long ll;

ll cache[101][10][1 << 10];

// 점화식
// dp(n, num) = num(n-1, num-1) + num(n-1, num+1)
ll dp(int n, int num, int set = 0)
{
    // 기저사례
    if (n == 1)
    {
        // 맨 첫자리수가 0인 경우
        if (num == 0 || (set | (1 << num)) != ((1 << 10) - 1))
            return 0;
        // 나머지 경우의 수
        return 1;
    }

    // 메모이제이션
    ll &ret = cache[n][num][set];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = 0;
    if (num != 9)
    {

        ret += dp(n - 1, num + 1, set | (1 << num));
    }

    if (num != 0)
    {
        ret += dp(n - 1, num - 1, set | (1 << num));
    }

    ret %= DIV;

    return ret;
}

int main()
{
    int n;
    ll ans = 0;
    memset(cache, -1, sizeof(cache));

    cin >> n;

    for (int i = 0; i <= 9; ++i)
    {
        ans += dp(n, i);
        ans %= DIV;
    }

    cout << ans << '\n';

    return 0;
}