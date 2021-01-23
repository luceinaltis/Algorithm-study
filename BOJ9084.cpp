#include <iostream>
#include <vector>
using namespace std;

vector<int> coins;
vector<int> cache;

/*
 *  중복의 의미에 대해 생각해보자..
 */

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n;
        int m;

        cin >> n;

        coins.assign(n, 0);
        cache.assign(10001, 0);
        cache[0] = 1;

        for (int i = 0; i < n; ++i)
        {
            cin >> coins[i];
        }

        cin >> m;

        int ans = 0;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= m; ++j)
            {
                cache[j] += cache[j - coins[i]];
            }
        }

        cout << cache[m] << '\n';
    }

    return 0;
}