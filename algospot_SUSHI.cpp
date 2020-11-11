#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<int> price;
vector<int> pref;

int cache[201];

int sushi3()
{
    int ret = 0;
    cache[0] = 0;
    for (int budget = 1; budget <= m; ++budget)
    {
        int cand = 0;
        for (int dish = 0; dish < n; ++dish)
        {
            if (budget >= price[dish])
                cand = max(cand, cache[(budget - price[dish]) % 201] + pref[dish]);
        }
        cache[budget % 201] = cand;
        ret = max(ret, cand);
    }
    return ret;
}

int main()
{
    int c;

    cin >> c;

    while (c--)
    {

        cin >> n >> m;

        m /= 100;

        price.assign(n, 0);
        pref.assign(n, 0);

        for (int i = 0; i < n; ++i)
        {
            cin >> price[i] >> pref[i];

            price[i] /= 100;
        }

        cout << sushi3() << '\n';
    }

    return 0;
}