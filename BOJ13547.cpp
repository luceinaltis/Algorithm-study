#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int sq;
int arr[100001];
int cnt[1000001];
int ans = 0;
int queriesAns[100000];
pair<pair<int, int>, int> queries[100000];

bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    if (a.first.first / sq == b.first.first / sq)
        return a.first.second < b.first.second;
    return a.first.first < b.first.second;
}

void add(int idx)
{
    if (cnt[arr[idx]] == 0)
        ans += 1;
    cnt[arr[idx]] += 1;
}

void sub(int idx)
{
    cnt[arr[idx]] -= 1;
    if (cnt[arr[idx]] == 0)
        ans -= 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    memset(cnt, 0, sizeof(cnt));

    cin >> n;
    sq = sqrt(n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;

        cin >> a >> b;

        queries[i].first.first = a;
        queries[i].first.second = b;
        queries[i].second = i;
    }

    sort(queries, queries + m, compare);

    // offline queries
    int s = 0, e = 0;
    for (int i = 0; i < m; ++i)
    {
        int tmpS = queries[i].first.first, tmpE = queries[i].first.second;
        for (int j = s; j < tmpS; ++j)
            sub(j);
        for (int j = e + 1; j <= tmpE; ++j)
            add(j);
        for (int j = tmpS; j < s; ++j)
            add(j);
        for (int j = tmpE + 1; j <= e; ++j)
            sub(j);

        s = tmpS;
        e = tmpE;

        queriesAns[queries[i].second] = ans;
    }

    for (int i = 0; i < m; ++i)
    {
        cout << queriesAns[i] << '\n';
    }

    return 0;
}