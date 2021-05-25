#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int n;

int calculate()
{
    vector<int> LIS;
    int arrSize = arr.size();
    for (int i = 0; i < arrSize; ++i)
    {
        int LISSize = LIS.size();
        int element = arr[i];

        int insertionIdx = lower_bound(LIS.begin(), LIS.end(), element) - LIS.begin();
        if (insertionIdx < LISSize)
        {
            LIS[insertionIdx] = element;
        }
        else
        {
            LIS.push_back(element);
        }
    }

    int ret = LIS.size();
    return ret;
}

int main()
{
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << calculate() << '\n';

    return 0;
}