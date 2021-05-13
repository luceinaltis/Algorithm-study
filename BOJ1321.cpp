#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
int arr[500000];
int sqrtArr[100000];

int query(int num)
{
    int sq = sqrt(n);
    int sqrtSize = (n / sq) + 1;

    for (int i = 0; i < sqrtSize; ++i)
    {
        if (sqrtArr[i] < num)
        {
            num -= sqrtArr[i];
        }
        else
        {
            for (int j = i * (sq); j < (i + 1) * sq; ++j)
            {
                if (arr[j] < num)
                {
                    num -= arr[j];
                }
                else
                {
                    return j + 1;
                }
            }
        }
    }
    return -1;
}

void update(int i, int diff)
{
    int sq = sqrt(n);
    arr[i] += diff;
    sqrtArr[i / sq] += diff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(arr, 0, sizeof(arr));
    memset(sqrtArr, 0, sizeof(sqrtArr));

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int sq = sqrt(n);
        cin >> arr[i];
        sqrtArr[i / sq] += arr[i];
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;

        cin >> a;

        switch (a)
        {
        case 1:
            cin >> b >> c;
            update(b - 1, c);
            break;
        case 2:
            cin >> b;
            cout << query(b) << '\n';
            break;
        default:
            break;
        }
    }

    return 0;
}