#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int mp[1000][1000];
int cache[1000][1000];

int dp(int tmpN, int tmpM)
{
    // 기저사례
    if (tmpN < 0 || tmpM < 0)
        return 0;

    if (mp[tmpN][tmpM] != 0)
        return 0;

    // 메모이제이션
    int &ret = cache[tmpN][tmpM];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = 1000;
    ret = min(ret, dp(tmpN - 1, tmpM - 1));
    ret = min(ret, dp(tmpN - 1, tmpM));
    ret = min(ret, dp(tmpN, tmpM - 1));
    ret += 1;

    return ret;
}

int main()
{
    int m, n;
    memset(cache, -1, sizeof(cache));

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mp[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans = max(ans, dp(i, j));
        }
    }
    cout << ans << '\n';

    return 0;
}