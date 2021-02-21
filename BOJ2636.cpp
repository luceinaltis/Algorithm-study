#include <iostream>
#include <vector>
using namespace std;

int height, width;
vector<vector<int>> mp;
vector<vector<int>> visited;

// n 시간 후 남은 치즈 갯수를 저장
vector<int> leftCount;

// 위, 오른, 아래, 왼
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    visited[x][y] = 1;

    // 경우의 수
    for (int i = 0; i < 4; ++i)
    {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (nextX < 0 || height <= nextX)
            continue;
        if (nextY < 0 || width <= nextY)
            continue;

        if (mp[nextX][nextY] == 1)
        {
            mp[nextX][nextY] = 2;
        }

        if (visited[nextX][nextY] == 0 && mp[nextX][nextY] == 0)
        {
            dfs(nextX, nextY);
        }
    }
}

// 한 턴 동안 공기를 노출시키자.
int exposeAir()
{
    visited.assign(height, vector<int>(width, 0));
    // 노출 된 치즈 삭제
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (mp[i][j] == 2)
            {
                mp[i][j] = 0;
            }
        }
    }

    // 공기 노출
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 || i == height - 1)
            {
                if (mp[i][j] == 0)
                {
                    dfs(i, j);
                }
            }

            if (j == 0 || i == width - 1)
            {
                if (mp[i][j] == 0)
                {
                    dfs(i, j);
                }
            }
        }
    }

    // 남은 치즈 카운트
    int count = 0;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (mp[i][j])
                count += 1;
        }
    }

    if (count != 0)
    {
        leftCount.push_back(count);
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    cin >> height >> width;

    mp.assign(height, vector<int>(width, -1));

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            cin >> mp[i][j];
        }
    }

    while (exposeAir())
    {
    }

    cout << leftCount.size() << '\n';
    cout << leftCount.back() << '\n';

    return 0;
}