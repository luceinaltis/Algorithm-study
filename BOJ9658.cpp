#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// first : 남은 돌 수, second : 턴 0 => 상근, 턴 1 => 창영
int cache[1001][2];

// 좋은 문제
// 알고리즘이 아닌 수학적 사고력을 물어본다.
int dp(int n, int turn = 0)
{
    // 기저사례
    // 나의 턴일 때
    // 돌을 모두 가져간 상태라면 나의 승리
    if (n == 0)
        return turn;

    // 메모이제이션
    int &ret = cache[n][turn];
    if (ret != -1)
        return ret;

    // 경우의 수
    // 이 턴은 진다는 가정을 하자
    ret = !turn;
    // 만약 하나라도 이기는 경우가 생긴다면 이긴다고 기록
    if (n - 1 >= 0 && dp(n - 1, !turn) == turn)
        ret = turn;
    if (n - 3 >= 0 && dp(n - 3, !turn) == turn)
        ret = turn;
    if (n - 4 >= 0 && dp(n - 4, !turn) == turn)
        ret = turn;

    return ret;
}

int main()
{
    int n;

    cin >> n;

    memset(cache, -1, sizeof(cache));

    int winner = dp(n);

    switch (winner)
    {
    case 0:
        cout << "SK" << '\n';
        break;
    case 1:
        cout << "CY" << '\n';
        break;
    default:
        break;
    }

    return 0;
}