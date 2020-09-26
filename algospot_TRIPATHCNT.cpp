#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

// 1 ~ n의 범위
// 0부터 할 지, 1부터 할 지 정하고 시작하자..

// 첫번째 동적 계획법의 캐시
int cache1[101][101];
// 두번째 동적 계획법의 캐시
ll cache2[101][101];
// 실제 삼각형의 값을 저장하자.
int tri[101][101];

int n;

// 탑다운
// dp1(int x, int y) : 삼각형 (x, y) 위치에서의 최대 경로 크기를 반환하자.
// 점화식 : dp1(x, y) = tri[x, y] + max(dp1(x+1, y), dp1(x+1, y+1))
int dp1(int x, int y)
{
    // 기저사례
    // 삼각형의 끝에 도달하면 실제 삼각형의 값을 반환하자.
    if(x >= n) return cache1[x][y] = tri[x][y]; 

    // 메모이제이션
    int& ret = cache1[x][y];
    if(ret != -1) return ret;

    // 점화식
    return cache1[x][y] = tri[x][y] + max(dp1(x+1, y), dp1(x+1, y+1));
}

// 탑다운
// dp2(int x, int y) : 삼각형 (x, y) 위치에서의 최대 경로의 수를 반환하자.
// 점화식 : dp2(x, y)
//                  = 1. cache1[x+1][y] > cache1[x+1][y+1]일 때 dp2(x+1, y) 대입
//                  = 2. cache1[x+1][y] < cache1[x+1][y+1]일 때 dp2(x+1, y+1) 대입
//                  = 3. cache1[x+1][y] == cache1[x+1][y+1]일 때 dp2(x+1, y) + dp2(x+1, y+1) 대입
ll dp2(int x, int y)
{
    // 기저사례
    // 삼각형의 끝에 도달하면 경로의 수 1을 반환하자.
    if(x >= n) return cache2[x][y] = 1;

    // 메모이제이션
    ll& ret = cache2[x][y];
    if(ret != -1) return ret;

    // 점화식
    if(cache1[x+1][y] > cache1[x+1][y+1])
        return cache2[x][y] = dp2(x+1, y);

    if(cache1[x+1][y] < cache1[x+1][y+1])
        return cache2[x][y] = dp2(x+1, y+1);

    if(cache1[x+1][y] == cache1[x+1][y+1])
        return cache2[x][y] = dp2(x+1, y) + dp2(x+1, y+1);
}

int main()
{
    int c;

    cin >> c;

    while(c--)
    {
        memset(cache1, -1 ,sizeof(cache1));
        memset(cache2, -1 ,sizeof(cache2));
        memset(tri, 0, sizeof(tri));

        cin >> n;

        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= i; ++j)
                cin >> tri[i][j];

        // cache1을 먼저 만들자.
        dp1(1, 1);

        cout << dp2(1, 1) << '\n';
    }
    return 0;
}