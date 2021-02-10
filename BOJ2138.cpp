#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string arrA, arrB;

int count(int isZeroOn)
{
    vector<int> checkArr;

    checkArr.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (arrA[i] == arrB[i])
        {
            checkArr[i] = 1;
        }
        else
        {
            checkArr[i] = 0;
        }
    }

    int ret = 0;
    if (isZeroOn == 1)
    {
        checkArr[0] = (!checkArr[0]);
        checkArr[1] = (!checkArr[1]);
        ret += 1;
    }

    for (int i = 1; i < n; ++i)
    {
        if (checkArr[i - 1] == 0)
        {
            ret += 1;
            checkArr[i - 1] = (!checkArr[i - 1]);
            checkArr[i] = (!checkArr[i]);
            if (i != n - 1)
                checkArr[i + 1] = (!checkArr[i + 1]);
        }
    }

    if (checkArr[n - 1] == 0)
    {
        return -1;
    }
    else
    {
        return ret;
    }
}

int main()
{
    cin >> n;
    cin >> arrA;
    cin >> arrB;

    int resultOn = count(1);
    int resultOff = count(0);

    if (resultOn == -1 && resultOff == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        int ans = 987654321;
        if (resultOn != -1)
            ans = min(ans, resultOn);
        if (resultOff != -1)
            ans = min(ans, resultOff);

        cout << ans << '\n';
    }

    return 0;
}