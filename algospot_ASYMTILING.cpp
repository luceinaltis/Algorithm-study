#include <iostream>
#include <vector>
#include <cstring>
#define DIV 1000000007
using namespace std;

typedef long long ll;

// 메모이제이션
ll cache[101];
int n;

// 점화식
// dp[n] = dp(n-1) + dp(n-2)
ll tiling(int tmpN)
{
    // 기저사례
    // 2 * 1일 때
    if(tmpN == 1) return 1;
    // 2 * 0일 때
    if(tmpN == 0) return 1;

    // 메모이제이션
    ll& ret = cache[tmpN];
    if(ret != -1) return ret;

    // 점화식
    return ret = (tiling(tmpN-1) + tiling(tmpN-2)) % DIV;
}

ll asymmetric(int width)
{
    // 전체 타일링에서 대칭을 빼자
    if(width % 2) 
    {
        // 홀수 일 경우
        return (tiling(width) - tiling(width/2) + DIV) % DIV;
    }
    else
    {
        // 짝수 일 경우
        return (tiling(width) - tiling(width/2) - tiling(width/2 - 1) + 2 * DIV) % DIV;
    }
}

ll cache2[101];

// 직접 비대칭이 몇 개 인지 세자
ll asymmetric2(int width)
{
    // 기저 사례
    if(width <= 2) return 0;
    // 메모이제이션
    ll& ret = cache2[width];
    if(ret != -1) return ret;

    // 점화식
    // (a)
    ret = asymmetric2(width - 2) % DIV;
    // (b)
    ret = (ret + asymmetric2(width - 4)) % DIV; 
    // (c)
    ret = (ret + tiling(width -3)) % DIV; 
    // (d)
    ret = (ret + tiling(width -3)) % DIV; 

    return ret;
}

int main()
{
    int c;
    cin >> c;

    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));

    while(c--)
    {
        cin >> n;

        cout << asymmetric2(n) << '\n';
    }

    return 0;
}