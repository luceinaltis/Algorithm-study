#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

vector<int> cacheASC;
vector<int> cacheDESC;

// 가장 길이가 긴 수열 반환
// 오름차순
int dpASC(int n)
{
    // 기저사례
    if (n == 0)
        return 1;

    // 메모이제이션
    int &ret = cacheASC[n];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = 1;
    if (arr[n - 1] <= arr[n])
    {
        ret = max(ret, dpASC(n - 1) + 1);
    }
    else
    {
        dpASC(n - 1);
    }
    return ret;
}

// 가장 길이가 긴 수열 반환
// 내림차순
int dpDESC(int n)
{
    // 기저사례
    if (n == 0)
        return 1;

    // 메모이제이션
    int &ret = cacheDESC[n];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = 1;
    if (arr[n - 1] >= arr[n])
    {
        ret = max(ret, dpDESC(n - 1) + 1);
    }
    else
    {
        dpDESC(n - 1);
    }
    return ret;
}

int main()
{
    int n;

    cin >> n;

    arr.assign(n, 0);
    cacheASC.assign(n, -1);
    cacheDESC.assign(n, -1);

    cacheASC[0] = 1;
    cacheDESC[0] = 1;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    dpASC(n - 1);
    dpDESC(n - 1);

    int ans = 1;

    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, cacheASC[i]);
        ans = max(ans, cacheDESC[i]);
    }

    cout << ans << '\n';

    return 0;
}