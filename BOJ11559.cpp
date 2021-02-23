#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> mp;
int chainCount = 0;

// 위, 오른, 아래, 왼
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};
vector<vector<int>> visited;
vector<vector<int>> deleteVisited;

void deleteDfs(int x, int y, char ch)
{
    mp[x][y] = '.';
    deleteVisited[x][y] = 1;

    // 경우의 수
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (nextX < 0 || nextX >= 12)
            continue;
        if (nextY < 0 || nextY >= 6)
            continue;

        // 방문하지 않고, 같은 문자면 드가자
        if (deleteVisited[nextX][nextY] == 0 && mp[nextX][nextY] == ch)
        {
            deleteDfs(nextX, nextY, ch);
        }
    }
}

void dfs(int x, int y, char ch)
{
    visited[x][y] = 1;
    chainCount += 1;

    // 경우의 수
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (nextX < 0 || nextX >= 12)
            continue;
        if (nextY < 0 || nextY >= 6)
            continue;

        // 방문하지 않고, 같은 문자면 드가자
        if (visited[nextX][nextY] == 0 && mp[nextX][nextY] == ch)
        {
            dfs(nextX, nextY, ch);
        }
    }
}

// 한 번의 연쇄반응을 실행한다.
// 연쇄반응이 일어났다면 1을 반환하자.
int chain()
{
    visited.assign(12, vector<int>(6, 0));
    int ret = 0;

    // 터트리기
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (visited[i][j] == 0 && mp[i][j] != '.')
            {
                chainCount = 0;
                dfs(i, j, mp[i][j]);
                if (chainCount >= 4)
                {
                    ret = 1;
                    deleteVisited.assign(12, vector<int>(6, 0));
                    deleteDfs(i, j, mp[i][j]);
                }
            }
        }
    }

    // 터트린 자리 메꾸기
    for (int i = 11; i >= 0; i--)
    {
        for (int j = 0; j < 6; ++j)
        {
            for (int k = 0; k < 12; ++k)
            {
                if (mp[i][j] == '.')
                {
                    for (int l = i; l > 0; l--)
                    {
                        mp[l][j] = mp[l - 1][j];
                    }

                    mp[0][j] = '.';
                }
            }
        }
    }

    return ret;
}

int main()
{
    mp.assign(12, "");

    for (int i = 0; i < 12; ++i)
    {
        cin >> mp[i];
    }

    int ans = 0;
    while (chain())
    {
        ans += 1;
    }

    cout << ans << '\n';

    return 0;
}