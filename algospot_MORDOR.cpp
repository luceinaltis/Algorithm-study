#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, q;

vector<int> sign;

class RMMQ {
private:
    int* nodeMin;
    int* nodeMax;

public:
    // 생성자
    RMMQ() 
    {
        nodeMin = new int[n*4]();
        nodeMax = new int[n*4]();
        initMin(nodeMin, 1, n, 1);
        initMax(nodeMax, 1, n, 1);
    }

    // 소멸자
    ~RMMQ() 
    {
        delete[] nodeMin;
        delete[] nodeMax;
    }

    // 구간 최소 쿼리
    int initMin(int* array, int left, int right, int node) 
    {
        if(left == right) return nodeMin[node] = sign[left];
        int mid = (left + right) / 2;
        int leftMin = initMin(array, left, mid, node * 2);
        int rightMin = initMin(array, mid+1, right, node * 2 + 1);
        return nodeMin[node] = min(leftMin, rightMin);
    }

    int queryMin(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        // 범위가 하나도 겹치지 않을 때
        if(nodeRight < left || right < nodeLeft) return 20000;
        // 범위가 전부 겹칠 때
        if(left <= nodeLeft && nodeRight <= right) return nodeMin[node];

        int mid = (nodeLeft + nodeRight) / 2;
        int leftMin = queryMin(left, right, node*2, nodeLeft, mid);
        int rightMin = queryMin(left, right, node*2 + 1, mid+1, nodeRight);

        return min(leftMin, rightMin);
    }

    // 구간 최대 쿼리
    int initMax(const int* array, int left, int right, int node) 
    {
        if(left == right) return nodeMax[node] = sign[left];
        int mid = (left + right) / 2;
        int leftMax = initMax(array, left, mid, node * 2);
        int rightMax = initMax(array, mid+1, right, node * 2 + 1);
        return nodeMax[node] = max(leftMax, rightMax);
    }

    int queryMax(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        // 범위가 하나도 겹치지 않을 때
        if(nodeRight < left || right < nodeLeft) return 0;
        // 범위가 전부 겹칠 때
        if(left <= nodeLeft && nodeRight <= right) return nodeMax[node];

        int mid = (nodeLeft + nodeRight) / 2;
        int leftMax = queryMax(left, right, node*2, nodeLeft, mid);
        int rightMax = queryMax(left, right, node*2 + 1, mid+1, nodeRight);

        return max(leftMax, rightMax);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c;

    cin >> c;

    while(c--)
    {

        cin >> n >> q;

        sign.assign(n+1, 0);

        for(int i = 1; i <= n; ++i)
        {
            cin >> sign[i];
        }

        RMMQ mmq;

        // 제작한 구간 쿼리 클래스를 바탕으로 최댓값과 최솟값의 차이를 구한다.
        for(int i = 0; i < q; ++i)
        {
            int a, b;

            cin >> a >> b;
            int rangeMax = mmq.queryMax(a+1, b+1, 1, 1, n);
            int rangeMin = mmq.queryMin(a+1, b+1, 1, 1, n);

            cout << rangeMax - rangeMin << '\n';
        }
    }
    return 0;
}