#include <bits/stdc++.h>
#define DIV 1000000007
using namespace std;

typedef long long ll;

class SegmentTree
{
private:
    vector<ll> segmentTree;
    vector<ll> arr;
    int arrSize;

    ll init(int start, int end, int node)
    {
        if (start == end)
        {
            return this->segmentTree[node] = this->arr[start];
        }

        int mid = (start + end) / 2;
        return this->segmentTree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % DIV;
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        this->arr.assign(arr.begin(), arr.end());
        this->arrSize = arr.size() - 1;
        this->segmentTree.assign(4 * this->arrSize, 0);

        init(1, this->arrSize, 1);
    }

    ll update(int idx, ll val)
    {
        return update(1, this->arrSize, 1, idx, val);
    }

    ll update(int start, int end, int node, int idx, ll val)
    {
        if (end < idx || idx < start)
            return this->segmentTree[node];
        if (start == end)
        {
            return this->segmentTree[node] = val;
        }

        int mid = (start + end) / 2;
        return this->segmentTree[node] = (update(start, mid, node * 2, idx, val) * update(mid + 1, end, node * 2 + 1, idx, val)) % DIV;
    }

    ll query(int left, int right)
    {
        return this->query(1, this->arrSize, 1, left, right);
    }

    ll query(int start, int end, int node, int left, int right)
    {
        if (end < left || right < start)
            return 1;
        if (left <= start && end <= right)
            return this->segmentTree[node];

        int mid = (start + end) / 2;
        return (query(start, mid, node * 2, left, right) * query(mid + 1, end, node * 2 + 1, left, right)) % DIV;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    vector<int> arr;

    cin >> n >> m >> k;
    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    for (int i = 0; i < m + k; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        switch (a)
        {
        case 1:
            segTree.update(b, c);
            break;
        case 2:
            cout << segTree.query(b, c) << '\n';
            break;
        default:
            break;
        }
    }
    return 0;
}