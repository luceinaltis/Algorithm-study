#include <bits/stdc++.h>
#define DIVISOR 1000000007LL
using namespace std;

typedef long long ll;

struct FenwickTree {
private:
    vector<ll> treeSumDist;
    vector<ll> treeSumIdx;
public:
    FenwickTree(int n) : treeSumDist(n+1), treeSumIdx(n+1) {}

    ll sumDist(int pos) {
        ++pos;
        ll ret = 0;
        while(pos > 0) {
            ret += treeSumDist[pos];

            pos &= (pos-1);
        }
        return ret;
    }

    void addSumDist(int pos, int val) {
        ++pos;
        while(pos < treeSumDist.size()) {
            treeSumDist[pos] += val;

            pos += (pos & (-pos));
        }
    }

    ll sumIdx(int pos) {
        ++pos;
        ll ret = 0;
        while(pos > 0) {
            ret += treeSumIdx[pos];

            pos &= (pos-1);
        }
        return ret;
    }

    void addSumIdx(int pos, int val) {
        ++pos;
        while(pos < treeSumIdx.size()) {
            treeSumIdx[pos] += val;

            pos += (pos & (-pos));
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    FenwickTree tree(200000);

    ll ans = 1;

    // 펜윅트리를 이용해서 문제를 풀자.
    // 1. 구간에 심어진 나무의 개수 합를 반환하는 쿼리
    // 2. 구간에 나무들의 거리의 합을 반환하는 쿼리
    // 두 개의 쿼리를 이용하자.
    for(int treeIdx = 1; treeIdx <= n; ++treeIdx)
    {
        ll treePos;
        cin >> treePos;

        // 왼쪽 나무의 개수
        ll leftTreeCount = tree.sumIdx(treePos);
        // 현재 나무부터 왼쪽 나무들과의 거리 합
        ll leftSumDist = (leftTreeCount * treePos) - tree.sumDist(treePos);

        // 오른쪽 나무의 개수
        ll rightTreeCount = tree.sumIdx(199999) - tree.sumIdx(treePos);
        // 현재 나무부터 오른쪽 나무들과의 거리 합
        ll rightSumDist = tree.sumDist(199999) - tree.sumDist(treePos) - (rightTreeCount * treePos);

        ll cost = (leftSumDist+rightSumDist);

        if(treeIdx != 1)
            // 왜 오버플로우가 날까...
            
            // long long의 범위는 –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
            // 아무리 long long이라해도 곱하기에서 오버플로우가 날 수 있다
            // 모듈라 연산을 변수 하나하나에 하는 습관을 들이자
            ans = ((ans%DIVISOR) * (cost%DIVISOR)) % DIVISOR;

        // 갱신해주는 함수
        tree.addSumDist(treePos, treePos);
        tree.addSumIdx(treePos, 1);
    }

    cout << ans << '\n';

    return 0;
}