#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#pragma warning(disable : 4996)
using namespace std;

int n, m;
int sq;
int arr[100001];
int cnt[1000001];
int ans = 0;
int queriesAns[100000];

struct Query
{
    int start, end, idx;
    bool operator<(const Query &a)
    {
        if ((this->start / sq) == (a.start / sq))
            return this->end < a.end;
        return (this->start / sq) < (a.start / sq);
    }
} queries[100000];

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
    scanf("%d", &n);
    sq = sqrt(n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        queries[i].start = a;
        queries[i].end = b;
        queries[i].idx = i;
    }

    sort(queries, queries + m);

    // offline queries
    int s = 0, e = 0;
    for (int i = 0; i < m; ++i)
    {
        int tmpS = queries[i].start, tmpE = queries[i].end;
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

        queriesAns[queries[i].idx] = ans;
    }

    for (int i = 0; i < m; ++i)
    {
        printf("%d\n", queriesAns[i]);
    }

    return 0;
}