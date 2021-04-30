#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int arr[100001];
ll cumulativeSum[100001];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll sum = 0;
    memset(arr, 0, sizeof(arr));

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
        cumulativeSum[i] = sum;
    }

    for (int j = 0; j < m; ++j)
    {
        int from, to;

        cin >> from >> to;

        cout << cumulativeSum[to] - cumulativeSum[from - 1] << '\n';
    }

    return 0;
}