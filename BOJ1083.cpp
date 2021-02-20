#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int n, s;

    cin >> n;

    arr.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cin >> s;

    // 각각의 자리값을 돌면서
    for (int i = 0; i + 1 < n; ++i)
    {
        if (s == 0)
            break;

        int maxIdx = -1;
        int maxValue = arr[i];

        // 남아 있는 s 범위 중에서 가장 큰 숫자를 교환한다.
        for (int j = i + 1; j < n; ++j)
        {
            if (s >= j - i && maxValue < arr[j])
            {
                maxIdx = j;
                maxValue = arr[j];
            }
        }

        if (maxIdx != -1)
        {
            for (int j = maxIdx; j > i; j--)
            {
                swap(arr[j], arr[j - 1]);
            }
            s -= (maxIdx - i);
        }
    }

    for (int j = 0; j < n; ++j)
    {
        cout << arr[j] << ' ';
    }
    cout << '\n';

    return 0;
}