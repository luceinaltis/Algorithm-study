#include <iostream>
#include <cstring>
using namespace std;

int n;
int cache[1000001];

int dp(int tmpN)
{
    // 기저 사례
    if (tmpN == 0)
        return 1;
    if (tmpN < 0)
        return 0;

    // 메모이제이션
    int &ret = cache[tmpN];
    if (ret != -1)
        return ret;

    // 탐색
    // 점화식 : dp(tmpN) = dp(tmpN - 1) + dp(tmpN - 2);
    return cache[tmpN] = (dp(tmpN - 1) + dp(tmpN - 2)) % 15746;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> n;

    cout << dp(n) << '\n';

    return 0;
}