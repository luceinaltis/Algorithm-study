#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int l[5000], m[5000], g[5000];

// 최적화 문제를 결정문제로 바꾸자!
// dist 지점까지 가면서 k개 이상의 표지판을 만날 수 있을까?
bool decision(int dist)
{
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dist >= l[i] - m[i])
        {
            ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
        }
    }
    return ret >= k;
}

// k번째 표지판을 만나는 지점의 위치를 계산한다.
int optimize()
{
    int lo = -1, hi = 8030001;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (decision(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    return hi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            cin >> l[i] >> m[i] >> g[i];
        }

        cout << optimize() << '\n';
    }
    return 0;
}