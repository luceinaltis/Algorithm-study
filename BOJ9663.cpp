#include <iostream>
#include <vector>
using namespace std;

int n;
int answer = 0;

vector<int> getPossiblePos(int tmpRow, vector<int> &visited)
{
    vector<int> ret;

    ret.assign(n, 1);

    for (int row = 0; row < tmpRow; ++row)
    {
        int impCol1 = visited[row];
        int impCol2 = visited[row] - (tmpRow - row);
        int impCol3 = visited[row] + tmpRow - row;

        ret[impCol1] = 0;
        if (0 <= impCol2 && impCol2 < n)
        {
            ret[impCol2] = 0;
        }

        if (0 <= impCol3 && impCol3 < n)
        {
            ret[impCol3] = 0;
        }
    }
    return ret;
}

void bf(int tmpRow, vector<int> &visited)
{
    // 기저사례
    if (tmpRow == n)
    {
        answer += 1;
        return;
    }

    // 현재 row에서 가능한 것을 선택하자
    vector<int> possiblePos = getPossiblePos(tmpRow, visited);
    for (int col = 0; col < n; ++col)
    {
        // 만약 가능하다면
        if (possiblePos[col])
        {
            visited[tmpRow] = col;
            bf(tmpRow + 1, visited);
            visited[tmpRow] = 0;
        }
    }
}

int main()
{
    cin >> n;

    vector<int> visited;

    visited.assign(n, 0);

    bf(0, visited);

    cout << answer << '\n';

    return 0;
}