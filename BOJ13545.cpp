#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
private:
    // first : -1의 개수, second : 1의 개수
    vector<pair<int, int>> segmentTree;
    vector<int> arr;
    int arrSize;

    int min(const int a, const int b)
    {
        return a < b ? a : b;
    }

    pair<int, int> init(int start, int end, int node)
    {
        if (start == end)
        {
            return this->segmentTree[node] = (this->arr[start] == -1 ? make_pair(1, 0) : make_pair(0, 1));
        }

        int mid = (start + end) / 2;
        pair<int, int> leftNode = init(start, mid, node * 2);
        pair<int, int> rightNode = init(mid + 1, end, node * 2 + 1);

        return this->segmentTree[node] = {leftNode.first + rightNode.first, leftNode.second + rightNode.second};
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        int treeSize = arr.size() * 4;

        this->arrSize = arr.size() - 1;
        this->arr.assign(arr.begin(), arr.end());
        this->segmentTree.assign(treeSize, pair<int, int>());

        init(1, this->arrSize, 1);
    }

    int query(int left, int right)
    {
        pair<int, int> result = this->query(1, this->arrSize, 1, left, right);
        return (this->min(result.first, result.second)) * 2;
    }

    pair<int, int> query(int start, int end, int node, int left, int right)
    {
        // 쿼리 범위안에 포함되지 않으면
        if (right < start || end < left)
        {
            return {0, 0};
        }
        // 쿼리 범위안에 완전히 포함된다면
        if (left <= start && end <= right)
        {
            return this->segmentTree[node];
        }

        int mid = (start + end) / 2;
        pair<int, int> leftNode = this->query(start, mid, node * 2, left, right);
        pair<int, int> rightNode = this->query(mid + 1, end, node * 2 + 1, left, right);

        return {leftNode.first + rightNode.first, leftNode.second + rightNode.second};
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

    SegmentTree segmentTree(arr);

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        cout << segmentTree.query(a, b) << '\n';
    }

    return 0;
}