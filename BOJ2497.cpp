#include <iostream>
#include <cstring>
#include <string>
#define LIMIT 1000000000000000LL
using namespace std;

typedef long long ll;

pair<ll, ll> memo[101][101];
int n, m;

pair<ll, ll> dp(int tmpN, int tmpM)
{
    // 기저사례
    if (tmpN == tmpM || tmpM == 0)
        return {0, 1};

    // 메모이제이션
    pair<ll, ll> &ret = memo[tmpN][tmpM];
    if (ret.first != -1 && ret.second != -1)
        return ret;

    // 점화식
    // dp(tmpN, tmpM) = dp(tmpN-1, tmpM) + dp(tmpN-1, tmpM-1)
    ll tmpSangwi = dp(tmpN - 1, tmpM).first + dp(tmpN - 1, tmpM - 1).first;
    ll tmpHawi = dp(tmpN - 1, tmpM).second + dp(tmpN - 1, tmpM - 1).second;
    if (tmpHawi >= LIMIT)
    {
        tmpSangwi += (tmpHawi / LIMIT);
        tmpHawi %= LIMIT;
    }
    return memo[tmpN][tmpM] = {tmpSangwi, tmpHawi};
}

int main()
{
    memset(memo, -1, sizeof(memo));

    cin >> n >> m;

    pair<ll, ll> answer = dp(n, m);
    if (answer.first == 0)
    {
        cout << answer.second << '\n';
    }
    else
    {
        string strHawi = to_string(answer.second);
        cout << answer.first;
        for (int i = 0; i < 15 - strHawi.size(); ++i)
        {
            cout << 0 << '\n';
        }
        cout << strHawi << '\n';
    }

    return 0;
}