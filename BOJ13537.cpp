#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTree
{
private:
    vector<vector<int>> segmentTree;
    int n;

    const vector<int> &init(int start, int end, int node, const vector<int> &arr)
    {
        // 리프 노드
        if (start == end)
        {
            this->segmentTree[node].push_back(arr[start]);
            return this->segmentTree[node];
        }

        // 분할
        int mid = (start + end) / 2;
        const vector<int> &leftNode = init(start, mid, node * 2, arr);
        const vector<int> &rightNode = init(mid + 1, end, node * 2 + 1, arr);

        // 정복
        int i = 0, j = 0;
        while (i < leftNode.size() && j < rightNode.size())
        {
            // 오름차 순으로 정렬
            if (leftNode[i] < rightNode[j])
            {
                this->segmentTree[node].push_back(leftNode[i++]);
            }
            else
            {
                this->segmentTree[node].push_back(rightNode[j++]);
            }
        }

        while (i < leftNode.size())
        {
            this->segmentTree[node].push_back(leftNode[i++]);
        }

        while (j < rightNode.size())
        {
            this->segmentTree[node].push_back(rightNode[j++]);
        }
        return this->segmentTree[node];
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        int treeSize = arr.size() * 4 + 1;
        this->segmentTree.assign(treeSize, vector<int>());
        this->n = arr.size() - 1;

        init(1, n, 1, arr);
    }

    int query(int start, int end, int node, int left, int right, int k)
    {
        // node의 범위가 벗어났을 때
        if (end < left || right < start)
        {
            return 0;
        }
        // node의 범위가 안에 포함 될 때
        if (left <= start && end <= right)
        {
            return this->segmentTree[node].size() - (upper_bound(this->segmentTree[node].begin(), this->segmentTree[node].end(), k) - this->segmentTree[node].begin());
        }
        // 걸쳐 있을 때
        int mid = (start + end) / 2;
        return query(start, mid, node * 2, left, right, k) + query(mid + 1, end, node * 2 + 1, left, right, k);
    }

    int query(int left, int right, int k)
    {
        return query(1, n, 1, left, right, k);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<int> arr;

    cin >> n;

    arr.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    SegmentTree tmpTree(arr);

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, k;

        cin >> a >> b >> k;

        cout << tmpTree.query(a, b, k) << '\n';
    }

    return 0;
}