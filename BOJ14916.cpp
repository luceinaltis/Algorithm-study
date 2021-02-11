#include <iostream>
using namespace std;

int main()
{
    int n;
    int ans = 0;

    cin >> n;

    switch (n % 10)
    {
    case 0:
        ans = (n / 5);
        break;
    case 1:
        n -= 6;
        ans = (n / 5) + 3;
        break;
    case 2:
        n -= 2;
        ans = (n / 5) + 1;
        break;
    case 3:
        n -= 8;
        ans = (n / 5) + 4;
        break;
    case 4:
        n -= 4;
        ans = (n / 5) + 2;
        break;
    case 5:
        ans = (n / 5);
        break;
    case 6:
        n -= 6;
        ans = (n / 5) + 3;
        break;
    case 7:
        n -= 2;
        ans = (n / 5) + 1;
        break;
    case 8:
        n -= 8;
        ans = (n / 5) + 4;
        break;
    case 9:
        n -= 4;
        ans = (n / 5) + 2;
        break;
    }

    if (n < 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}