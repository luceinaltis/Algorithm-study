#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int conNum[100001];

/**
 *  @param arr 현재 배열
 *  @param value
 */
int findLowerBound(vector<int> &arr, int value)
{
    int size = arr.size();
    int start = 0, end = size - 1;

    while (start < end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] < value)
        {
            start = mid + 1;
        }
        else if (value <= arr[mid])
        {
            end = mid;
        }
    }

    return end;
}

int calculate()
{
    vector<int> arr;
    for (int i = 1; i <= n; ++i)
    {
        if (arr.size() == 0 || arr.back() <= conNum[i])
        {
            arr.push_back(conNum[i]);
        }
        else if (arr.back() > conNum[i])
        {
            int changeIdx = findLowerBound(arr, conNum[i]);
            arr[changeIdx] = conNum[i];
        }
    }

    return n - arr.size();
}

int main()
{
    memset(conNum, 0, sizeof(conNum));

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> conNum[i];
    }

    cout << calculate() << '\n';

    return 0;
}