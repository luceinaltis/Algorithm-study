#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int foodSize;

vector<vector<int>> board, visited;

// 위, 오른쪽, 아래, 왼쪽
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, 1, 0, -1};

int max(const int a, const int b)
{
    return a > b ? a : b;
}

// DFS로 접근해도, BFS로 접근해도 둘 다 풀 수 있다.
// 색칠하는 문제
// foodSize 전역 변수는 음식물의 크기를 나타낸다.
void dfs(int x, int y)
{   
    foodSize += 1;

    // 위, 오른, 아래, 왼을 다 체크한다.
    for(int i = 0; i < 4; ++i)
    {
        int nextX = x + dir_x[i];
        int nextY = y + dir_y[i];

        // 범위를 벗어났는지 체크!
        if(nextX < 1 || n < nextX) continue;
        if(nextY < 1 || m < nextY) continue;

        // 방문하지 않고 연결되어 있는 음식물이라면
        if(!visited[nextX][nextY] && board[nextX][nextY] == 1)
        {
            visited[nextX][nextY] = 1;
            dfs(nextX, nextY);
        }
    }
}

int solve()
{
    int ret = 0;

    // 맵 전부를 탐색하자.
    // 방문하지 않은 좌표이고, 쓰레기가 있다면 DFS를 실행하자.
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(!visited[i][j] && board[i][j] == 1)
            {
                // DFS의 경우
                // 맨 처음 시작점의 visited를 놓치는 경우가 많다.. 조심!
                visited[i][j] = 1;
                dfs(i, j);
                ret = max(ret, foodSize);
                foodSize = 0;
            }
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m >> k;

    board.assign(n+1, vector<int>(m+1, 0));
    visited.assign(n+1, vector<int>(m+1, 0));

    for(int i = 0; i < k; ++i)
    {
        int r, c;

        cin >> r >> c;

        board[r][c] = 1;
    }

    cout << solve() << '\n';

    return 0;
}