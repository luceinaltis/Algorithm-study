#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

char board[100][100];
char boardAfterMove[100][100];
int visited[100][100];
int visited1[100][100];
int javelin[100];
int r, c, n;
// 위, 오른, 아래, 왼
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

// 현재 집합의 클러스터 좌표들을 반환하자
void dfsArr(int x, int y, vector<pair<int, int>> &arr)
{
    arr.push_back({x, y});
    visited1[x][y] = 1;

    // 탐색
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (nextX < 0 || r <= nextX)
            continue;
        if (nextY < 0 || c <= nextY)
            continue;

        if (visited1[nextX][nextY] == 0 && board[nextX][nextY] == 'x')
        {
            dfsArr(nextX, nextY, arr);
        }
    }
}

// 0을 반환하면 움직여야하는 클러스터 그룹이다.
int dfs(int x, int y)
{
    int ret = 0;

    visited[x][y] = 1;
    if (x == r - 1)
    {
        return 1;
    }

    // 탐색
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (nextX < 0 || r <= nextX)
            continue;
        if (nextY < 0 || c <= nextY)
            continue;

        if (visited[nextX][nextY] == 0 && board[nextX][nextY] == 'x')
        {
            if (dfs(nextX, nextY))
            {
                ret = 1;
            }
        }
    }

    return ret;
}

// direction : false는 왼쪽, true는 오른쪽에서 던지는 것
void javelinThrow(int height, bool direction)
{
    int tmpX = r - height, tmpY;

    for (int i = 0; i < c; ++i)
    {
        if (direction == false)
        {
            tmpY = i;
        }
        else
        {
            tmpY = c - i - 1;
        }

        if (board[tmpX][tmpY] == 'x')
        {
            board[tmpX][tmpY] = '.';
            break;
        }
    }
}

void execute(int height, bool direction)
{
    memset(visited, 0, sizeof(visited));
    memset(visited1, 0, sizeof(visited1));
    vector<pair<int, int>> cluster;

    // 창 던지기
    javelinThrow(height, direction);

    // 이동해야하는 클러스터 표시
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (board[i][j] == 'x' && visited[i][j] == 0)
            {
                if (dfs(i, j) == 0)
                {
                    dfsArr(i, j, cluster);
                }
            }
        }
    }

    // 클러스터 지우기
    for (int i = 0; i < cluster.size(); ++i)
    {
        int clusterX = cluster[i].first;
        int clusterY = cluster[i].second;
        board[clusterX][clusterY] = '.';
    }

    // 얼만큼 이동해야하는지(k)구하기
    int k = 0;
    bool isOut = false;
    while (!isOut && !cluster.empty())
    {
        k++;

        for (int i = 0; i < cluster.size(); ++i)
        {
            int clusterX = cluster[i].first;
            int clusterY = cluster[i].second;

            if (board[clusterX + k][clusterY] == 'x' || clusterX + k >= r)
            {
                isOut = true;
                break;
            }
        }
    }

    // 이동한 만큼 처리해주기
    for (int i = 0; i < cluster.size(); ++i)
    {
        int clusterX = cluster[i].first;
        int clusterY = cluster[i].second;

        board[clusterX + k - 1][clusterY] = 'x';
    }
}

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> board[i][j];
        }
    }

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int height;
        bool direction = (i % 2 == 0 ? false : true);

        cin >> height;

        execute(height, direction);
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}