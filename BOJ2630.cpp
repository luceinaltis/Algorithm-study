#include <iostream>
#include <cstring>
using namespace std;

int space[129][129];
int n; 

int white = 0;
int blue = 0;

void divide(const int startX, const int startY, const int length) {
    bool isBlue = true, isWhite = true, isDivide = false;

    // 현재 사각형이 쪼개져야하는지 아닌지를 판단한다. 판단결과는 isDivide에 저장
    for(int x = startX; x < startX + length; ++x) {
        for(int y = startY; y < startY + length; ++y) {
            if(space[x][y]) {
                isWhite = false;
            } else {
                isBlue = false;
            }
            if(!isWhite && !isBlue) {
                isDivide = true;
                break;
            }
        }
        if(!isWhite && !isBlue) {
            break;
        }
    }

    // 쪼개야 한다면 쪼개자
    if(isDivide) {
        int subLength = length / 2;
        divide(startX, startY, subLength);
        divide(startX, startY + subLength, subLength);
        divide(startX + subLength, startY, subLength);
        divide(startX + subLength, startY + subLength, subLength);
    } else {
        // 안쪼개도 된다면 색종이의 개수를 더해주자.
        if(isWhite) white++;
        if(isBlue) blue++;
    }
}

int main()
{
    memset(space, 0, sizeof(space));

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> space[i][j];
        }
    }

    divide(1, 1, n);

    cout << white << '\n';
    cout << blue << '\n';
    return 0;
}