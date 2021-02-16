#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
vector<int> picked;

int calculate()
{
    int ret = 0;
    // d날 마다 풀 과제를 선정하자.
    for (int i = 1000; i >= 1; --i)
    {
        int maxW = -1;
        int pickedIdx = -1;
        for (int j = 0; j < arr.size(); ++j)
        {
            int d = arr[j].first;
            int w = arr[j].second;

            // 과제를 할 수 있는 것 중에 가장 높은 것을 뽑자.
            if (d >= i && picked[j] == 0 && maxW < w)
            {
                pickedIdx = j;
                maxW = w;
            }
        }
        if (maxW != -1 && pickedIdx != -1)
        {
            ret += maxW;
            picked[pickedIdx] = 1;
        }
    }

    return ret;
}

int main()
{
    int n;

    cin >> n;

    arr.assign(n, pair<int, int>());
    picked.assign(1000, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    cout << calculate() << '\n';

    return 0;
}