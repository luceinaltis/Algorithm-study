#include <iostream>
#include <cstring>
using namespace std;

// 위, 오른, 아래, 왼
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};
int board[500][500];
int memoization[500][500];
int m, n;

// dfs로 경로의 개수를 세보자..
int dfs(int x, int y)
{
    // 기저사례
    if (x == m - 1 && y == n - 1)
    {
        return memoization[x][y] = 1;
    }

    // 메모이제이션
    int &ret = memoization[x][y];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        // 보드를 벗어나면 건너뛰자
        if (nextX < 0 || nextX >= m)
            continue;
        if (nextY < 0 || nextY >= n)
            continue;

        if (board[nextX][nextY] < board[x][y])
        {
            ret += dfs(nextX, nextY);
        }
    }

    // 반환이 필요한 함수에 반환을 했는지 안했는지 잘 살펴보자..
    return ret;
}

int main()
{

    cin >> m >> n;

    memset(board, 0, sizeof(board));
    memset(memoization, -1, sizeof(memoization));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}