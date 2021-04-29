#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// up, right, down, left
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

int n;
vector<string> painting;
vector<vector<int>> visited;

void bfs(int x, int y, bool isColorBlindness)
{
    queue<pair<int, int>> que;

    // 초기화
    que.push({x, y});

    while (!que.empty())
    {
        pair<int, int> tmp = que.front();
        que.pop();

        int tmpX = tmp.first;
        int tmpY = tmp.second;
        char tmpColor = painting[tmpX][tmpY];
        if (isColorBlindness && tmpColor == 'G')
        {
            tmpColor = 'R';
        }

        if (visited[tmpX][tmpY])
            continue;
        visited[tmpX][tmpY] = 1;

        for (int i = 0; i < 4; ++i)
        {
            int nextX = tmpX + dirX[i];
            int nextY = tmpY + dirY[i];
            char nextColor = ' ';

            if (nextX < 0 || n <= nextX)
                continue;
            if (nextY < 0 || n <= nextY)
                continue;

            nextColor = painting[nextX][nextY];
            if (isColorBlindness && nextColor == 'G')
            {
                nextColor = 'R';
            }

            if (visited[nextX][nextY] == 0 && tmpColor == nextColor)
            {
                que.push({nextX, nextY});
            }
        }
    }
}

int countSector(bool isColorBlindness = false)
{
    int ret = 0;
    visited.assign(n, vector<int>(n, 0));

    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < n; ++y)
        {
            if (visited[x][y] == 0)
            {
                bfs(x, y, isColorBlindness);
                ret += 1;
            }
        }
    }
    return ret;
}

int main()
{

    cin >> n;

    painting.assign(n, string());

    for (int i = 0; i < n; ++i)
    {
        cin >> painting[i];
    }

    cout << countSector(false) << ' ' << countSector(true) << '\n';

    return 0;
}