#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

int calculate()
{
    int ret = 0;

    sort(arr.begin(), arr.end(), less<int>());

    int i = 0;
    int last = 0;
    // 왼쪽
    while (i < arr.size() && arr[i] < 0)
    {
        if ((i % m) == 0)
        {
            ret += abs(arr[i]) * 2;
            last = max(abs(arr[i]), last);
        }

        i += 1;
    }

    // 오른쪽
    i = (arr.size() - 1);
    int tmpM = 0;
    while (i >= 0 && arr[i] > 0)
    {
        if ((tmpM % m) == 0)
        {
            ret += abs(arr[i]) * 2;
            tmpM = 0;
            last = max(abs(arr[i]), last);
        }

        tmpM += 1;
        i -= 1;
    }

    return ret - last;
}

int main()
{

    cin >> n >> m;

    arr.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << calculate() << '\n';

    return 0;
}