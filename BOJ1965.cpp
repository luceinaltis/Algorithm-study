#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> cache;

int dp(int pos)
{
    // 메모이제이션
    int &ret = cache[pos];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1;
    for (int i = 0; i < pos; ++i)
    {
        // 작은 부분만 처리해주자.
        if (arr[i] < arr[pos])
        {
            ret = max(ret, dp(i) + 1);
        }
    }
    return ret;
}

int main()
{
    int n;
    int ans = 1;

    cin >> n;

    arr.assign(n, 0);
    cache.assign(n, -1);

    for (int i = 0; i < arr.size(); ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < cache.size(); ++i)
    {
        dp(i);
        ans = max(ans, cache[i]);
    }

    cout << ans << '\n';

    return 0;
}