#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// (y, x)의 형태
const int dx[2] = {-1, 1};
const int dy[2] = {1, 1};

// 보드판
vector<string> board;

// 대각선으로 묶인다
int id[2][8][8];

int n, m;
int adj[64][64];

vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    for (int b = 0; b < m; b++)
        if (adj[a][b])
            // b가 매칭되었다면 bMatch[b]부터 시작
            if (bMatch[b] == -1 || dfs(bMatch[b]))
            {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
    return false;
}
int bipartiteMatch()
{
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);
    int size = 0;
    for (int start = 0; start < n; start++)
    {
        visited = vector<bool>(n, false);
        if (dfs(start))
            size++;
    }
    return size;
}

int placeBishops()
{
    memset(id, -1, sizeof(id));
    int count[2] = {0, 0};
    // 네트워크 유량을 위한 전처리 작업
    for (int dir = 0; dir < 2; ++dir)
    {
        for (int y = 0; y < board.size(); ++y)
        {
            for (int x = 0; x < board.size(); ++x)
            {
                // 실제 보드에 놓을 수 있고
                // 대각선 묶음이 비어있다면
                if (board[y][x] == '.' && id[dir][y][x] == -1)
                {
                    int cy = y, cx = x;
                    while (0 <= cy && cy < board.size() && 0 <= cx && cx < board.size() && board[cy][cx] == '.')
                    {
                        // count를 세어가면서 실제 이분그래프 위치를 저장한다.
                        id[dir][cy][cx] = count[dir];
                        cy += dy[dir];
                        cx += dx[dir];
                    }
                    count[dir] += 1;
                }
            }
        }
    }

    n = count[0];
    m = count[1];
    memset(adj, 0, sizeof(adj));

    for (int y = 0; y < board.size(); ++y)
    {
        for (int x = 0; x < board.size(); ++x)
        {
            if (board[y][x] == '.')
            {
                adj[id[0][y][x]][id[1][y][x]] = 1;
            }
        }
    }
    return bipartiteMatch();
}

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int boardSize;

        cin >> boardSize;

        board.assign(boardSize, string(boardSize, '.'));
        for (int i = 0; i < boardSize; ++i)
        {
            cin >> board[i];
        }
        cout << placeBishops() << '\n';
    }

    return 0;
}