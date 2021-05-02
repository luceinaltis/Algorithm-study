#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int n, m;
int board[1025][1025];
int cumSum[1025][1025];

void calculateCumulativeSum()
{

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cumSum[i][j] = board[i][j] + cumSum[i][j - 1] + cumSum[i - 1][j] - cumSum[i - 1][j - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(board, 0, sizeof(board));
    memset(cumSum, 0, sizeof(cumSum));

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
        }
    }

    calculateCumulativeSum();

    for (int i = 0; i < m; ++i)
    {
        int x1, y1, x2, y2;
        ll result = 0;

        cin >> x1 >> y1 >> x2 >> y2;

        result = cumSum[x2][y2] - cumSum[x1 - 1][y2] - cumSum[x2][y1 - 1] + cumSum[x1 - 1][y1 - 1];

        cout << result << '\n';
    }

    return 0;
}