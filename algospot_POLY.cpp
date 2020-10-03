#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 10*1000*1000;
int cache[101][101];

int poly(int n, int first)
{
    // 기저사례
    if(n == first) return 1;

    // 메모이제이션
    int& ret = cache[n][first];
    if(ret != -1) return ret;

    // 점화식
    ret = 0;
    for(int second = 1; second <= n - first; second++)
    {
        int add = second + first - 1;
        add *= poly(n - first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;   
    }

    return ret;
}

int main()
{
    int C;
    memset(cache, -1, sizeof(cache));

    cin >> C;

    while(C--)
    {
        int n;
        int ans = 0;

        cin >> n;
        
        for(int i = 1; i <= n; ++i)
        {
            ans += poly(n, i);
            ans %= MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}