#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int sq;
vector<int> arr;

class SegmentTree
{
private:
    vector<vector<int>> segmentTree;
    vector<int> arr;

    const vector<int> &init(int start, int end, int node)
    {
        int i, j, mid, leftNodeSize, rightNodeSize;
        if (start == end)
        {
            this->segmentTree[node].push_back(arr[start]);
            return this->segmentTree[node];
        }

        mid = (start + end) / 2;
        const vector<int> &leftNode = init(start, mid, node * 2);
        const vector<int> &rightNode = init(mid + 1, end, node * 2 + 1);

        i = 0;
        j = 0;
        leftNodeSize = leftNode.size();
        rightNodeSize = rightNode.size();
        while (i < leftNodeSize && j < rightNodeSize)
        {
            if (leftNode[i] < rightNode[j])
            {
                this->segmentTree[node].push_back(leftNode[i++]);
            }
            else
            {
                this->segmentTree[node].push_back(rightNode[j++]);
            }
        }

        while (i < leftNodeSize)
        {
            this->segmentTree[node].push_back(leftNode[i++]);
        }

        while (j < rightNodeSize)
        {
            this->segmentTree[node].push_back(rightNode[j++]);
        }

        return this->segmentTree[node];
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        int arrSize = arr.size();
        this->arr.assign(arr.begin(), arr.end());
        this->segmentTree.assign(arrSize * 4, vector<int>());

        init(1, arrSize - 1, 1);
    }

    int query(int left, int right, int val)
    {
        int arrSize = this->arr.size();
        return query(1, arrSize - 1, 1, left, right, val);
    }

    // 구간 안에서 val보다 크거나 같은 수의 갯수를 반환한다.
    int query(int start, int end, int node, int left, int right, int val)
    {
        int ret;
        // 쿼리 범위에 포함되지 않을 때
        if (end < left || right < start)
            return 0;
        // 쿼리 범위에 완전히 포함 될 때
        if (left <= start && end <= right)
        {
            ret = this->segmentTree[node].end() - lower_bound(this->segmentTree[node].begin(), this->segmentTree[node].end(), val);
            return ret;
        }

        int mid = (start + end) / 2;
        return this->query(start, mid, node * 2, left, right, val) + this->query(mid + 1, end, node * 2 + 1, left, right, val);
    }
};

struct Queries
{
    int start;
    int end;
    int idx;

    bool operator<(const Queries &a)
    {
        if (this->start / sq == a.start / sq)
        {
            return this->end < a.end;
        }
        return this->start / sq < a.start / sq;
    }
};

int sub(int idx, SegmentTree &segmentTree, int ts, int te, int k)
{
    return -segmentTree.query(ts, te, arr[idx] + k + 1) + segmentTree.query(ts, te, arr[idx] - k);
}

int add(int idx, SegmentTree &segmentTree, int ts, int te, int k)
{
    return -segmentTree.query(ts, te, arr[idx] + k + 1) + segmentTree.query(ts, te, arr[idx] - k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    vector<Queries> queries;
    vector<int> ansArr;

    cin >> n >> k;
    sq = sqrt(n);
    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    SegmentTree segmentTree(arr);

    cin >> m;
    queries.assign(m, Queries());
    ansArr.assign(m, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> queries[i].start >> queries[i].end;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    int s = 0, e = 0;
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int ns = queries[i].start;
        int ne = queries[i].end;
        int idx = queries[i].idx;

        for (int j = s; j < ns; ++j)
            ans -= sub(j, segmentTree, j + 1, e, k);
        for (int j = e + 1; j <= ne; ++j)
            ans += add(j, segmentTree, s, j - 1, k);
        for (int j = s - 1; j >= ns; --j)
            ans += add(j, segmentTree, j + 1, e, k);
        for (int j = e; j > ne; --j)
            ans -= sub(j, segmentTree, s, j - 1, k);

        s = ns;
        e = ne;

        ansArr[idx] = ans;
    }

    for (int i = 0; i < m; ++i)
    {
        cout << ansArr[i] << '\n';
    }

    return 0;
}