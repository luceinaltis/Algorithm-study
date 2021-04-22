#include <iostream>
using namespace std;

int n, k;
int arr[100000];

int main()
{
    cin >> n >> k;

    int start = 0, end = k - 1;
    int sum = 0;

    // input
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < k; ++i)
    {
        sum += arr[i];
    }

    int maxSum = sum;
    for (int i = end + 1; i < n; ++i)
    {
        sum += arr[i];
        sum -= arr[start++];

        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }

    cout << maxSum << '\n';

    return 0;
}