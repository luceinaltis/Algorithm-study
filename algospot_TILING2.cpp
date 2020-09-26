#include <iostream>
#include <cstring>
#define DIV 1000000007
using namespace std;

typedef long long ll;

ll cache[101];

// 1 ~ n까지 타일로 덮을 수 있는 경우의 수를 반환하자.
// 점화식 : dp(n) = dp(n-1) + dp(n-2)
ll dp(int n)
{
    // 기저사례
    if(n <= 0) return 0;

    // 메모이제이션
    ll& ret = cache[n];
    if(ret != -1) return ret;

    // 동적계획법
    return cache[n] = (dp(n-1) + dp(n-2)) % DIV;
}

int main()
{   
    int c;

    cin >> c;

    memset(cache, -1, sizeof(cache));
    // 메모이제이션 초기화
    cache[1] = 1;
    cache[2] = 2;

    while(c--)
    {
        int n;

        cin >> n;

        cout << dp(n) << '\n';
    }

    return 0;
}