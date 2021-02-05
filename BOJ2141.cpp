#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
vector<pair<ll, ll>> arr;

ll find(ll start, ll end)
{
    sort(arr.begin(), arr.end());

    ll sum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        sum += arr[i].second;
    }

    if (sum % 2)
    {
        sum /= 2;
        sum += 1;
    }
    else
    {
        sum /= 2;
    }

    ll tmp = 0;
    ll idx = 0;
    while (tmp < sum)
    {
        tmp += arr[idx++].second;
    }

    return arr[idx - 1].first;
}

int main()
{
    cin >> n;

    arr.assign(n, pair<ll, ll>(0, 0));

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    cout << find(-1000000000, 1000000000) << '\n';

    return 0;
}