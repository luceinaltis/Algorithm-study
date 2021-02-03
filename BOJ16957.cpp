#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dirX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dirY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

enum DIRECTION
{
    UP_LEFT,
    UP,
    UP_RIGHT,
    RIGHT,
    DOWN_RIGHT,
    DOWN,
    DOWN_LEFT,
    LEFT,
    NONE,
};

int chessPan[501][501];
int ans[501][501];
int r, c;

vector<vector<pair<int, int>>> cache;

// 현재 위치에서 이동할 위치를 반환한다.
int checkNextPos(int tmpR, int tmpC)
{
    int next = NONE;

    int tmpValue = chessPan[tmpR][tmpC];
    int tmpMin = tmpValue;
    for (int i = 0; i < 8; ++i)
    {
        int nextR = tmpR + dirX[i];
        int nextC = tmpC + dirY[i];

        // 범위를 벗어날 때는 계산하지말자
        if (nextR < 0 || r <= nextR)
            continue;
        if (nextC < 0 || c <= nextC)
            continue;

        if (tmpMin > chessPan[nextR][nextC])
        {
            tmpMin = chessPan[nextR][nextC];
            next = i;
        }
    }

    return next;
}

pair<int, int> dp(int tmpR, int tmpC)
{
    // 기저사례
    int nextPos = checkNextPos(tmpR, tmpC);
    if (nextPos == NONE)
        return cache[tmpR][tmpC] = make_pair(tmpR, tmpC);

    // 메모이제이션
    pair<int, int> &ret = cache[tmpR][tmpC];
    if (ret != pair<int, int>(-1, -1))
        return ret;

    // 경우의 수
    int nextR = tmpR + dirX[nextPos];
    int nextC = tmpC + dirY[nextPos];
    ret = dp(nextR, nextC);
    return ret;
}

int main()
{
    cin >> r >> c;

    memset(chessPan, -1, sizeof(chessPan));
    cache.assign(r, vector<pair<int, int>>(c, {-1, -1}));

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> chessPan[i][j];
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            pair<int, int> result = dp(i, j);

            ans[result.first][result.second] += 1;
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}