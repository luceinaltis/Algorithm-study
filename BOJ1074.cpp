#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll ans = 0;

// height, width크기의 사각형에서 (r, c)에 몇번째로 도착하는지 반환한다.
void divide(const ll length, int r, int c) {
    if(length == 0) return;
    ll subLength = length / 2;

    // 왼쪽 위
    if(r < subLength && c < subLength) {
        divide(subLength, r, c);
        return;
    }
    // 오른쪽 위
    if(r < subLength && c >= subLength) {
        ans += subLength * subLength * 1;
        divide(subLength, r, c - subLength);
        return;
    }


    // 왼쪽 아래
    if(r >= subLength && c < subLength) {
        ans += subLength * subLength * 2;
        divide(subLength, r - subLength, c);
        return;
    }


    // 오른쪽 아래
    if(r >= subLength && c >= subLength) {
        ans += subLength * subLength * 3;
        divide(subLength, r - subLength , c - subLength);
        return;
    }
}

int main()
{
    ll N, r, c;

    cin >> N >> r >> c;

    divide(pow(2, N), r, c);

    cout << ans << '\n';

    return 0;
}