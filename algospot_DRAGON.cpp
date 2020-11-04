#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 점화식
void bf(int leftGen, string str)
{
    // 기저사례
    if (leftGen == 0)
    {
        cout << str;
        return;
    }

    // 완전탐색
    for (int i = 0; i < str.size(); ++i)
    {
        switch (str[i])
        {
        case 'F':
        case '+':
        case '-':
            cout << str[i];
            break;
        case 'X':
            bf(leftGen - 1, "X+YF");
            break;
        case 'Y':
            bf(leftGen - 1, "FX-Y");
            break;
        }
    }
}

int main()
{
    int c;

    cin >> c;

    while (c--)
    {
        int n, p, l;

        cin >> n >> p >> l;

        bf(n, "FX");
    }
    return 0;
}