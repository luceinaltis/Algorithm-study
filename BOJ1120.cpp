#include <iostream>
#include <string>
using namespace std;

int max(const int& a, const int& b)
{
    return a > b ? a : b;
}

int main() {
    string a, b;

    cin >> a >> b;

    // a와 b를 겹쳐볼 때 겹치는 문자가 제일 많은 수
    int maxMatch = 0;

    // b의 문자들을 다 돌아보자
    for(int i = 0; i < b.size(); ++i)
    {
        // a가 얼마나 겹치는지 계산하자.
        int tmpMatch = 0;
        for(int j = 0; j < a.size(); ++j)
        {
            int tmpIndex = i + j;
            if(tmpIndex >= b.size())
            {
                tmpMatch = 0;
                break;
            }
            
            // 서로 겹치는 수를 체크하자.
            if(b[tmpIndex] == a[j]) tmpMatch += 1;
        }

        maxMatch = max(maxMatch, tmpMatch);
    }

    cout << (a.size() - maxMatch) << '\n';

    return 0;
}