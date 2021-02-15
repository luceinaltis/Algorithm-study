#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, ansArr;

int main()
{
    int n;

    cin >> n;

    arr.assign(n, 0);
    ansArr.assign(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> ansArr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != ansArr[i])
        {
            arr[i] = !(arr[i]);

            if (i + 1 < n)
            {
                arr[i + 1] = !(arr[i + 1]);
            }

            if (i + 2 < n)
            {
                arr[i + 2] = !(arr[i + 2]);
            }

            ans += 1;
        }
    }

    cout << ans << '\n';

    return 0;
}