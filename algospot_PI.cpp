#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

string str;
int cache[10000+1];

// start부터 end-1까지 난이도를 계산하여 반환하자.
int calculateDifficulty(int start, int end)
{
    string M = str.substr(start, end - start + 1);

    // 모든 숫자가 같은지 검사하자.
    if(M == string(M.size(), M[0])) return 1;

    bool progressive = true;
    // 등차 수열인지 검사하자.
    for(int i = 0; i < M.size()-1; ++i)
    {
        if(M[i+1] - M[i] != M[1] - M[0])
        {
            progressive = false;
        }
    }

    // 등차수열이고 차이가 1이라면..
    if(progressive && abs(M[1] - M[0]) == 1) return 2;

    // 두 숫자가 번갈아가면서 등장하는지 체크하자
    bool alternating = true;
    for(int i = 0; i < M.size(); ++i)
    {
        if(M[i] != M[i%2])
            alternating = false;
    }
    if(alternating) return 4;
    if(progressive) return 5;
    return 10;
}

// [...end] 까지 최소 합을 반환하자.
// 탑다운
int dp(int end)
{
    // size()는 unsigned int이니 알고 있자

    // 기저사례
    // 딱 떨어지면 0을 반환하자.
    if(end == -1) return 0;

    // 메모이제이션
    int& ret = cache[end];
    if(ret != -1) return ret;

    ret = INF;
    for(int next = 3; next <= 5; ++next)
    {
        if(end - next >= -1)
        {
            // dp(end)는 [...end]까지의 최솟값을 반환한다.
            ret = min(ret, dp(end-next) + calculateDifficulty(end-next + 1, end));
        }
    }
    return ret;
}

int main()
{
    int C;

    cin >> C;
    while(C--)
    {
        memset(cache, -1, sizeof(cache));

        cin >> str;
        cout << dp(str.size()-1) << '\n';
    }

    return 0;
}