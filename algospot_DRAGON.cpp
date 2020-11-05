// 기환
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000000000 + 1;
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

int length[51];
void precalc()
{
    length[0] = 1;
    for (int i = 1; i <= 50; ++i)
    {
        length[i] = min(MAX, 2 * length[i - 1] + 2);
    }
}

// dragonCurve => 한 글자씩 생각하기
char expand(const string &dragonCurve, int generations, int skip)
{
    // 기저사례
    if (generations == 0)
    {
        return dragonCurve[skip];
    }

    for (int i = 0; i < dragonCurve.size(); ++i)
    {
        if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y')
        {
            if (skip >= length[generations])
            {
                skip -= length[generations];
            }
            else if (dragonCurve[i] == 'X')
            {
                return expand(EXPAND_X, generations - 1, skip);
            }
            else
            {
                return expand(EXPAND_Y, generations - 1, skip);
            }
        }
        else if (skip > 0)
        {
            skip -= 1;
        }
        else
        {
            return dragonCurve[i];
        }
    }
    return '#';
}

int main()
{
    int c;

    cin >> c;

    precalc();

    while (c--)
    {
        int n, p, l;

        cin >> n >> p >> l;

        for (int pos = p; pos < p + l; ++pos)
        {
            cout << expand("FX", n, pos - 1);
        }
        cout << '\n';
    }

    return 0;
}