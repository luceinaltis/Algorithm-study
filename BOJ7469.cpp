#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> segmentTree;
vector<int> arr;
int n, m;

const vector<int> &init(int start, int end, int node)
{
    segmentTree[node].clear();
    if (start == end)
    {
        segmentTree[node].push_back(arr[start]);
        return segmentTree[node];
    }

    int mid = (start + end) / 2;
    const vector<int> &leftNode = init(start, mid, node * 2);
    const vector<int> &rightNode = init(mid + 1, end, node * 2 + 1);

    int i = 0, j = 0;
    int leftNodeSize = leftNode.size();
    int rightNodeSize = rightNode.size();
    while (i < leftNodeSize && j < rightNodeSize)
    {
        if (leftNode[i] < rightNode[j])
        {
            segmentTree[node].push_back(leftNode[i++]);
        }
        else
        {
            segmentTree[node].push_back(rightNode[j++]);
        }
    }

    while (i < leftNodeSize)
    {
        segmentTree[node].push_back(leftNode[i++]);
    }

    while (j < rightNodeSize)
    {
        segmentTree[node].push_back(rightNode[j++]);
    }

    return segmentTree[node];
}

int query(int start, int end, int node, int left, int right, int val)
{
    if (right < start || end < left)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return upper_bound(segmentTree[node].begin(), segmentTree[node].end(), val) - segmentTree[node].begin();
    }

    int mid = (start + end) / 2;
    return query(start, mid, node * 2, left, right, val) + query(mid + 1, end, node * 2 + 1, left, right, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    segmentTree.assign(n * 4, vector<int>());
    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    init(1, n, 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;

        cin >> a >> b >> c;

        int l = -1e9, r = 1e9;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (query(1, n, 1, a, b, mid) < c)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << l << '\n';
    }

    return 0;
}