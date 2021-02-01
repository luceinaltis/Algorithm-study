#include <iostream>
#include <cstring>
#define MAX_WIDTH 500
#define MAX_HEIGHT 500
using namespace std;

char miro[MAX_HEIGHT + 1][MAX_WIDTH + 1];
int cache[MAX_HEIGHT + 1][MAX_WIDTH + 1];

int n, m;

bool dp(int tmpN, int tmpM)
{
    // 기저사례
    if (tmpN < 1 || tmpN > n)
        return 1;
    if (tmpM < 1 || tmpM > m)
        return 1;

    // 메모이제이션
    int &ret = cache[tmpN][tmpM];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = 0;
    char dir = miro[tmpN][tmpM];
    switch (dir)
    {
    case 'U':
        ret = dp(tmpN - 1, tmpM);
        break;
    case 'R':
        ret = dp(tmpN, tmpM + 1);
        break;
    case 'D':
        ret = dp(tmpN + 1, tmpM);
        break;
    case 'L':
        ret = dp(tmpN, tmpM - 1);
        break;
    default:
        break;
    }
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> miro[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ans += dp(i, j);
        }
    }

    cout << ans << '\n';

    return 0;
}