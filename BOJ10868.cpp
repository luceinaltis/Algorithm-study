#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int n, m;
vector<int> arr;
vector<int> minTree;

int init(int start, int end, int nodeIdx)
{
    // 기저사례
    if (start == end)
        return minTree[nodeIdx] = arr[start];

    int mid = (start + end) / 2;
    int leftMin = init(start, mid, nodeIdx * 2);
    int rightMin = init(mid + 1, end, nodeIdx * 2 + 1);

    return minTree[nodeIdx] = min(leftMin, rightMin);
}

int getMin(int start, int end, int nodeIdx, int left, int right)
{
    // 범위를 벗어날 때
    if (end < left || right < start)
        return INF;
    // 범위 안 에 있을 때
    if (left <= start && end <= right)
        return minTree[nodeIdx];

    // 범위가 걸쳐 있을 때
    int mid = (start + end) / 2;
    return min(getMin(start, mid, nodeIdx * 2, left, right), getMin(mid + 1, end, nodeIdx * 2 + 1, left, right));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    minTree.assign(n * 4 + 1, 0);
    arr.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    init(1, n, 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;

        cin >> a >> b;

        cout << getMin(1, n, 1, a, b) << '\n';
    }

    return 0;
}