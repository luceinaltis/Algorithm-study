#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> names;
vector<int> capa;
vector<int> wants;

// 메모이제이션
// first : 물건 번호, second : 남은 용량
vector<vector<int>> cache;
// 최선의 선택을 저장하자.
vector<vector<int>> choices;

int n, w;

int max(int a, int b)
{
    return a > b ? a : b;
}

// 동적계획법
// tmpIdx+1부터 n까지 고려했을때 만들 수 있는 최고 절박도를 반환하자.
// 점화식 dp(현재 인덱스) = max(dp(현재 인덱스+1 ~ n))
int dp(int tmpIdx, int leftCapa)
{
    // 기저사례

    // 메모이제이션
    int &ret = cache[tmpIdx][leftCapa];
    if (ret != -1)
        return ret;

    ret = 0;
    // 점화식
    for (int nextIdx = tmpIdx + 1; nextIdx <= n; ++nextIdx)
    {
        // 만약 부피를 초과하지 않는다면
        // 주머니에 넣어보자
        if (leftCapa >= capa[nextIdx])
        {
            int tmp = ret;
            ret = max(ret, dp(nextIdx, leftCapa - capa[nextIdx]) + wants[nextIdx]);
            if (ret != tmp)
            {
                choices[tmpIdx][leftCapa] = nextIdx;
            }
        }
    }
    return ret;
}

// 가져갈 물건 개수 출력
int result1(int tmpIdx, int leftCapa)
{
    if (choices[tmpIdx][leftCapa] == -1)
        return 0;
    return result1(choices[tmpIdx][leftCapa], leftCapa - capa[choices[tmpIdx][leftCapa]]) + 1;
}

void result2(int tmpIdx, int leftCapa)
{
    if (choices[tmpIdx][leftCapa] == -1)
    {
        return;
    }
    else
    {
        cout << names[choices[tmpIdx][leftCapa]] << '\n';
        result2(choices[tmpIdx][leftCapa], leftCapa - capa[choices[tmpIdx][leftCapa]]);
    }
}

int main()
{
    int c;

    cin >> c;

    while (c--)
    {
        cin >> n >> w;

        // 물건 인덱스는 1 ~ n으로 정하자!
        names.assign(n + 1, string());
        wants.assign(n + 1, 0);
        capa.assign(n + 1, 0);
        cache.assign(n + 1, vector<int>(1001, -1));
        choices.assign(n + 1, vector<int>(1001, -1));

        for (int i = 1; i <= n; ++i)
        {
            cin >> names[i] >> capa[i] >> wants[i];
        }

        cout << dp(0, w) << ' ';

        // 가져갈 물건 개수 출력

        cout << result1(0, w) << '\n';

        // 가져갈 물건들 출력

        result2(0, w);
    }

    return 0;
}