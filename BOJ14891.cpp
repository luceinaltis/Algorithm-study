#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// N극은 0, S극은 1이다.
vector<string> prevState;
vector<string> nextState;
vector<int> isRotated;

int k;

int isRotate(const int leftIndex, const int rightIndex);
void rotate(const int &index, const int &direction);

// index 톱니바퀴를 direction방향으로 돌리자.
void rotate(const int &index, const int &direction)
{
    // 돌렸다고 체크하자.
    isRotated[index] = 1;
    // 해당 톱니를 먼저 돌린다.
    switch (direction)
    {
    case 1:
    {
        // 시계방향
        nextState[index] = prevState[index];

        const char tmp = nextState[index].back();
        for (int i = nextState[index].size() - 1; i > 0; --i)
        {
            nextState[index][i] = nextState[index][i - 1];
        }
        nextState[index][0] = tmp;
        break;
    }
    case -1:
    {
        // 반시계방향
        nextState[index] = prevState[index];

        const char tmp = nextState[index].front();
        for (int i = 1; i < nextState[index].size(); ++i)
        {
            nextState[index][i - 1] = nextState[index][i];
        }
        nextState[index][7] = tmp;
        break;
    }
    }

    // 근접한 톱니바퀴를 돌려야하는지 체크한 뒤 돌리자
    int right = index + 1;
    int left = index - 1;

    // 범위에 있고, 돌려야하고. 이미 돌리지 않았다면
    if (right < 4 && isRotate(index, right) && isRotated[right] == 0)
    {
        int nextDirection = direction == 1 ? -1 : 1;
        rotate(right, nextDirection);
    }

    if (left >= 0 && isRotate(left, index) && isRotated[left] == 0)
    {
        int nextDirection = direction == 1 ? -1 : 1;
        rotate(left, nextDirection);
    }
}

// 돌려야하면 1반환
// 아니면 0 반환
int isRotate(const int leftIndex, const int rightIndex)
{
    if (prevState[leftIndex][2] != prevState[rightIndex][6])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 점수를 계산하여 반환해주자.
int result()
{
    int ret = 0;

    if (prevState[0][0] == '1')
        ret += 1;

    if (prevState[1][0] == '1')
        ret += 2;

    if (prevState[2][0] == '1')
        ret += 4;

    if (prevState[3][0] == '1')
        ret += 8;
    return ret;
}

int main()
{
    prevState.assign(4, "");
    nextState.assign(4, "");

    for (int i = 0; i < 4; ++i)
    {
        cin >> prevState[i];
        nextState[i] = prevState[i];
    }

    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int index, direction;

        cin >> index >> direction;

        // 어느것을 돌렸는지 초기화시켜주자.
        isRotated.assign(4, 0);
        rotate(index - 1, direction);

        // 파이프라인
        for (int i = 0; i < 4; ++i)
        {
            prevState[i] = nextState[i];
        }
    }

    cout << result() << '\n';

    // 맞닿은 톱니의 극이 다르다면 회전방향의 반대방향으로 회전
    return 0;
}