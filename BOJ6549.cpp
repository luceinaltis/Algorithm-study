#include <bits/stdc++.h>
#define INF 1000000000LL
using namespace std;

typedef long long ll;

int n;

// 노드 초기화
int init(vector<int>& arr, vector<int>& nodes, int left, int right, int node) {
    if(left == right) return nodes[node] = left;

    int mid = (left + right)/2;
    int leftMinIndex = init(arr, nodes, left, mid, node*2);
    int rightMinIndex = init(arr, nodes, mid+1, right, node*2 + 1);

    if(arr[leftMinIndex] <= arr[rightMinIndex]) {
        nodes[node] = leftMinIndex;
    } else {
        nodes[node] = rightMinIndex;
    }

    return nodes[node];
}

// 쿼리
// 최솟 사각형 높이에 해당하는 인덱스를 반환하자.
int queryMin(vector<int>& arr, vector<int>& nodes, int left, int right, int node, int nodeLeft, int nodeRight) {
    // 겹치지 않을 때
    if(nodeRight < left || right < nodeLeft) return -1;
    // 완전 겹칠 때
    if(left <= nodeLeft && nodeRight <= right) return nodes[node];

    int mid = (nodeLeft + nodeRight) / 2;
    int leftMinIndex = queryMin(arr, nodes, left, right, node*2, nodeLeft, mid);
    int rightMinIndex = queryMin(arr, nodes, left, right, node*2 + 1, mid+1, nodeRight);

    if(leftMinIndex == -1) return rightMinIndex;
    if(rightMinIndex == -1) return leftMinIndex;

    int ret;
    if(arr[leftMinIndex] <= arr[rightMinIndex]) {
        ret = leftMinIndex;
    } else {
        ret = rightMinIndex;
    }

    return ret;
}

// 생각한 방법
// 분할정복법으로 풀자.
// 주어진 left ~ right 범위에서 높이가 가장 낮은 직사각형을 중심으로 셋으로 나누자.
// 나누어진 3개의 사각형 크기를 비교해서 가능한 최대 크기를 구해보자.
ll solve(vector<int>& arr, vector<int>& nodes, ll left, ll right) {
    // 기저사례 순서 주의
    // 기저사례 : 범위가 아예 사라졌을 때 사각형을 만들 수 없다.
    if(left > right) return 0;
    // 기저사례 : 더이상 쪼개질 수 없을 때 넓이를 반환하자.
    if(left == right) return arr[left];

    // left ~ right 범위에서 높이가 가장 낮은 사각형을 구하자.
    int minIndex = queryMin(arr, nodes, left, right, 1, 1, n);

    ll leftMax = solve(arr, nodes, left, minIndex-1);
    ll rightMax = solve(arr, nodes, minIndex+1, right);
    ll tmpMax = (right - left + 1) * arr[minIndex];

    return max(leftMax, max(rightMax, tmpMax)); 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while(cin >> n)
    {
        if(n == 0) break;

        vector<int> arr(n+1);

        int h = (int)(ceil(log2(n))+1e-9);
        int tree_size = (1 << (h + 1));
        // first : 최솟값
        // second : 최솟값의 인덱스
        vector<int> nodes(tree_size);

        for(int i = 1; i <= n; ++i) cin >> arr[i];

        init(arr, nodes, 1, n, 1);

        cout << solve(arr, nodes, 1, n) << '\n';
    }
    return 0;
}