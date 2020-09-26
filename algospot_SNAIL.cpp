#include <iostream>
using namespace std;

// https://jepo.tistory.com/26 => 배열 초기화 방법
// int arr[100] = { 2 } => arr[0]만 2로 초기화 됨, 0만 전부 초기화

// first : 현재 날짜 수
// second : 달팽이가 올라온 높이
double cache[1001][2*1000+1];

// n : 우물의 깊이
// m : 장마 기간
int n, m;

// days 날짜에 climbed 높이까지 오를 확률
// 점화식 : dp(days, climbed) = 0.75 * dp(days+1, climbed+2) + 0.25 * dp(days+1, climbed+1)
double dp(int days, int climbed)
{
    // 기저사례
    // 첫 날의 확률을 계산해주자.
    if(days == 1) { 
        if(climbed > 2) 
        {
            return cache[days][climbed] = 0;
        }
        else if(climbed == 2) 
        {
            return cache[days][climbed] = 0.75;
        } 
        else if(climbed <= 1)
        {
            // 최소 1만큼 올라갈 확률은 1이다 
            return cache[days][climbed] = 1;
        }
    }

    // 메모이제이션
    double& ret = cache[days][climbed];
    if(ret != -1.0f) return ret;

    // 점화식
    return cache[days][climbed] = 0.75 * dp(days-1, climbed-2) + 0.25 * dp(days-1, climbed-1);
}

int main()
{
    int c;

    cin >> c;
    
    // 소수점을 10자리로 고정하자.
    cout << fixed;
    cout.precision(10);

    // 초기화 값을 -1로 고정하자.
    // 초기화 값을 0으로 놓고 메모이제이션을 하면 오버헤드가 생길 수 있다.....
    for(int i = 0; i < 1001; ++i)
    {
        for(int j = 0; j < 2001; ++j)
        {
            cache[i][j] = -1.0f;
        }
    }

    while(c--)
    {
        cin >> n >> m;

        cout << dp(m, n) << '\n';
    }

    return 0;
}