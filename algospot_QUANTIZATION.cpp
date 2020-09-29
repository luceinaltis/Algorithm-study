#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, s;
int cache[101][11];
int pSum[101], pSqSum[101]; 
vector<int> arr;

// 전처리
// 부분 합을 처리해주기 위해 전처리를 하자.
// 시간 복잡도 : O(n)
int precalc()
{
    pSum[0] = arr[0];
    pSqSum[0] = arr[0] * arr[0];
    for(int i = 1; i < n; ++i)
    {
        // pSum : A[0] + ... + A[i]의 부분합
        pSum[i] = pSum[i-1] + arr[i];
        // pSqSum : A[0]^2 + ... + A[i]^2의 부분합
        pSqSum[i] = pSqSum[i-1] + arr[i]*arr[i];
    }
}

// arr[lo] ~ arr[hi] 범위에서 가장 최소한의 오차 제곱을 반환해주자.
// 평균값이 가장 최소가 되는 지점이 오차 제곱또한 최소가 된다.
// 시간 복잡도 : O(1)
int minError(int lo, int hi)
{
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);

    // 0.5를 더하는 이유
    // 기본적인 연산이 floor로 내림되기 때문에 반올림한 값을 사용하기 위해 0.5를 더해준다.
    // 반올림을 해줘야 답과 더 가까운 정수를 구할수 있기 때문에 쓰는듯
    int m = int(0.5 + (double)sum / (hi - lo + 1));

    int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
    return ret;
}   

// arr[from] ~ arr[n]까지 parts로 부분부분 묶었을 때
// 오차 제곱 합의 최소를 반환하자.
// 부분 문제 : O(ns)
int dp(int from, int parts)
{
    // 기저사례
    // 모든 숫자들을 양자화 했을 때
    if(from == n) return 0;
    // 숫자는 남았지만 묶는 방법을 전부 썼을 때
    // 숫자들을 전부 써야하므로 쓸모없는 값으로 처리해주자.
    if(parts == 0) return INF;

    // 메모이제이션
    int& ret = cache[from][parts];
    if(ret != -1) return ret;

    ret = INF;
    // 점화식
    for(int partSize = 1; from + partSize <= n; ++partSize)
    {
        ret = min(ret, minError(from, from + partSize - 1) + dp(from + partSize, parts - 1));
    }
    return ret;
}

int main()
{
    int c;

    cin >> c;

    while(c--)
    {
        cin >> n >> s;

        memset(pSum, 0, sizeof(pSum));
        memset(pSqSum, 0, sizeof(pSqSum));
        memset(cache, -1, sizeof(cache));
        arr.assign(n, 0);

        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        precalc();

        cout << dp(0, s) << '\n';
    }

    return 0;
}