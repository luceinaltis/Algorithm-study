#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// 펜윅트리
// 구간합을 구하는데 좋다.
// 왜 좋을까??
// 값을 갱신해주는데 O(logn)의 시간이 걸리기 때문에 자주 갱신되는 정보면 쓸만함
// 다만, 구간합이 아닌 최솟값, 최댓값 등등 구간에 대한 쿼리는 구간 트리를 이용하자.
struct FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n+1) {}

    // 0 ~ pos 까지의 구간 합을 반환해준다.
    int sum(int pos) {
        // 받는 배열은 0으로 시작한다는 약속이 있으므로
        // 펜윅트리의 비트마스크를 이용하기 위해 +1을 해주자.
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];

            // 맨 마지막 1인 비트를 없애주는 공식
            pos &= (pos-1);
        }
        return ret;
    }

    // 값을 갱신하는 함수
    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;

            // 맨 마지막 비트 1 자리에 +1을 해주는 공식
            pos += (pos & (-pos));
        }
    }
};

ll countMoves(const vector<int>& arr) {
    FenwickTree tree(1000000);
    ll ret = 0;
    for(int i = 0; i < arr.size(); ++i) {
        // arr[i] 보다 큰 수가 몇개나 나왔는지 구간합으로 구해서 더하자.
        ret += tree.sum(999999) - tree.sum(arr[i]);

        // arr[i]가 한번 출현했다고 갱신해주자.
        tree.add(arr[i], 1);
    }
    return ret;
}

int main()
{
    // 빠른 입력이 뭔지 궁금하면 참고하자
    // https://algospot.com/forum/read/2496/
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c;

    cin >> c;

    while(c--)
    {
        int n;

        cin >> n;

        vector<int> arr(n, 0);

        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        cout << countMoves(arr) << '\n';
    }

    return 0;
}