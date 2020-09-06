#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

enum DIRECTION { TOP, NORTH, EAST, SOUTH, WEST, BOTTOM };

int n, m, x, y, k;

// 지도
vector<vector<int>> __map;

class Dice {
private:
    // 전개도는 처음에 0으로 되어있다.
    int written[6];
    // 주사위의 현재 위치
    int x, y;
public:
    Dice(int x, int y) : written({0}), x(x), y(y) {};

    // roll함수들은 실패하면 -1을 리턴하고,
    // 성공하면 윗 면에 있는 수를 리턴한다.

    // 위로 굴리기
    int rollUp() 
    {
        if(x - 1 < 0) return -1;
        if(__map[x-1][y] == 0)
        {
            __map[x-1][y] = written[NORTH];
        }
        else 
        {
            written[NORTH] = __map[x-1][y];
            __map[x-1][y] = 0;
        }

        this->x = x - 1;

        int tmp[6];
        memcpy(tmp, written, sizeof(written));

        // 주사위의 top, ... , bottom을 바꾸자
        written[NORTH] = tmp[TOP];
        written[TOP] = tmp[SOUTH];
        written[SOUTH] = tmp[BOTTOM];
        written[BOTTOM] = tmp[NORTH];

        return written[TOP];
    }

    // 오른쪽으로 굴리기
    int rollRight() 
    {
        if(y + 1 >= m) return -1;
        if(__map[x][y + 1] == 0)
        {
            __map[x][y + 1] = written[EAST];
        }
        else 
        {
            written[EAST] = __map[x][y + 1];
            __map[x][y + 1] = 0;
        }

        this->y = y + 1;

        int tmp[6];
        memcpy(tmp, written, sizeof(written));

        // 주사위의 top, ... , bottom을 바꾸자
        written[EAST] = tmp[TOP];
        written[TOP] = tmp[WEST];
        written[WEST] = tmp[BOTTOM];
        written[BOTTOM] = tmp[EAST];

        return written[TOP];
    }

    // 아래로 굴리기
    int rollDown() 
    {
        if(x + 1 >= n) return -1;
        if(__map[x + 1][y] == 0)
        {
            __map[x + 1][y] = written[SOUTH];
        }
        else 
        {
            written[SOUTH] = __map[x + 1][y];
            __map[x + 1][y] = 0;
        }

        this->x = x + 1;

        int tmp[6];
        memcpy(tmp, written, sizeof(written));

        // 주사위의 top, ... , bottom을 바꾸자
        written[NORTH] = tmp[BOTTOM];
        written[TOP] = tmp[NORTH];
        written[SOUTH] = tmp[TOP];
        written[BOTTOM] = tmp[SOUTH];

        return written[TOP];
    }

    // 왼쪽으로 굴리기
    int rollLeft() 
    {
        if(y - 1 < 0) return -1;
        if(y - 1 >= m) return -1;
        if(__map[x][y - 1] == 0)
        {
            __map[x][y - 1] = written[WEST];
        }
        else 
        {
            written[WEST] = __map[x][y - 1];
            __map[x][y - 1] = 0;
        }

        this->y = y - 1;

        int tmp[6];
        memcpy(tmp, written, sizeof(written));

        // 주사위의 top, ... , bottom을 바꾸자
        written[WEST] = tmp[TOP];
        written[TOP] = tmp[EAST];
        written[EAST] = tmp[BOTTOM];
        written[BOTTOM] = tmp[WEST];

        return written[TOP];
    }
};

int main()
{
    cin >> n >> m >> x >> y >> k;

    __map.assign(n, vector<int>(m, 0));

    Dice tmpDice(x, y);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> __map[i][j];
        }
    }

    for(int i = 0; i < k; ++i)
    {
        int input, output;
        cin >> input;

        switch (input)
        {
        case 1:
            output = tmpDice.rollRight();
            break;
        case 2:
            output = tmpDice.rollLeft();
            break;
        case 3:
            output = tmpDice.rollUp();
            break;
        case 4:
            output = tmpDice.rollDown();
            break;
        }

        if(output == -1) continue;
        cout << output << '\n';
    }

    return 0;
}