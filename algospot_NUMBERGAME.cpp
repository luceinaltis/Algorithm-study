#include <iostream>
#include <cstring>
using namespace std;

const int EMPTY = -987654321;
int board[50];
int n;
int cache[50][50];

int play(int left, int right)
{
    // 기저사례
    if (left > right)
        return 0;

    int &ret = cache[left][right];
    if (ret != EMPTY)
        return ret;

    ret = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));

    if (right - left + 1 >= 2)
    {
        ret = max(ret, -play(left + 2, right));
        ret = max(ret, -play(left, right - 2));
    }
    return ret;
}

int main()
{
    int c;

    cin >> c;

    while (c--)
    {
        memset(board, 0, sizeof(board));
        memset(cache, -1, sizeof(cache));

        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> board[i];
        }

        cout << play(0, n - 1) << '\n';
    }
    return 0;
}