#include <iostream>
#include <string>
using namespace std;

/*
    🤔🤔🤔🤔
    버블 정렬

    - 정의
        정렬의 한 종류로 시간복잡도 O(n^2)를 가진다.
        인접한 두 요소의 비교를 통해 정렬이 진행된다.
        가장 큰(작은) 요소가 맨 끝으로 이동하기 때문에 이 모양이 마치 바다속에서 물거품들이 올라가는 모양과 비슷하다하여 붙여진 이름..
        만들기는 몹시 간단하지만 성능 문제때문에 절대 쓸 일은 없을듯..?
*/

void swap(string &num, int a, int b)
{
    char temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

int main()
{
    string input;

    cin >> input;

    for (int i = 0; i < input.size(); ++i)
    {
        for (int j = 0; j + 1 + i < input.size(); ++j)
        {
            if (int(input[j]) < int(input[j + 1]))
            {
                swap(input, j, j + 1);
            }
        }
    }

    cout << input << '\n';

    return 0;
}