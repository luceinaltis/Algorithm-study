#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[100000][4];

// 탑다운
// 현재 행까지 내려왔을 때의 최고점을 반환하자.
int dp(const vector<vector<int>>& land, int tmpRow, int tmpCol)
{
    // 기저사례
    // 행의 맨 처음에 도착했을 때는 선택한 Col을 반환해주자
    if(tmpRow == 0) return land[tmpRow][tmpCol];

    // 메모이제이션
    int& ret = cache[tmpRow][tmpCol];
    if(ret != -1) return ret;

    // 계산
    // 열을 돌면서 부분문제를 해결하자.
    ret = 0;
    for(int prevCol = 0; prevCol < 4; ++prevCol)
    {
        // 같은 열은 선택할 수 없으니 건너뛰자.
        if(prevCol == tmpCol) continue;

        ret = max(ret, dp(land, tmpRow-1, prevCol) + land[tmpRow][tmpCol]);
    }
    return ret;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;

    memset(cache, -1, sizeof(cache));

    answer = max(answer, dp(land, land.size()-1, 0));
    answer = max(answer, dp(land, land.size()-1, 1));
    answer = max(answer, dp(land, land.size()-1, 2));
    answer = max(answer, dp(land, land.size()-1, 3));

    return answer;
}