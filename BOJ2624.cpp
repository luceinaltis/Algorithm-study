#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> arr;
int cache[10001][100];

// 점화식
// dp(n, k) = dp(n, k-1) + dp(n - coin * 1, k - 1) + ... + dp(n - coin * count, k - 1)
int dp(int n, int k)
{
    // 기저사례
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    if (k < 0)
        return 0;

    // 메모이제이션
    int &ret = cache[n][k];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = 0;

    int coin = arr[k].first;
    int count = arr[k].second;
    for (int i = 0; i <= count; ++i)
    {
        ret += dp(n - coin * i, k - 1);
    }
    return ret;
}

int main()
{
    int t, k;

    cin >> t;
    cin >> k;

    arr.assign(k, pair<int, int>());
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < arr.size(); ++i)
    {
        int p;
        int n;

        cin >> p >> n;

        arr[i].first = p;
        arr[i].second = n;
    }

    cout << dp(t, arr.size() - 1) << '\n';

    return 0;
}