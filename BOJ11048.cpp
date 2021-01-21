#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> map;

int cache[1001][1001];

int max(int a, int b)
{
    return a > b ? a : b;
}

/*  동적계획법
 *      상당히 복잡해보이지만 원리를 이해하면 간단하다.
 *      분할정복(Divide and Conquer) 알고리즘과 상당히 비슷한 면이 있지만, 구별해야된다.
 *      하나의 문제를 여러개의 부분 문제로 쪼개고 그 부분 문제들을 해결하면 된다.
 *      단, 부분 문제를 해결할 때 다른 문제에서는 겹치는 부분 문제들이 있을 수 있는데 메모이제이션 기법을 이용해 최적화한다.
 *      시간복잡도는 (부분 문제의 수)x(각 부분 문제의 시각복잡도)로 계산하면 된다.
 *      메모이제이션 말고도 부분 문제의 시작점을 다르게 한다던지, 가능성이 없는 부분 문제는 먼저 잘라내는 방법 등을 이용해 다양하게 최적화 가능하다.
 *      알고리즘을 공부하면서 느끼는건 상당히 기본적인 개념이지만 정확히 이해하기는 정말 어려운 알고리즘인듯..?
 */
int dfs(int r, int c)
{
    // 기저사례
    // 칸을 벗어났을 경우 경로가 될 수 없으므로 0을 반환
    if (r > n || c > m)
        return 0;

    // 메모이제이션
    int &ret = cache[r][c];
    if (ret != -1)
        return ret;

    // 경우의 수
    ret = max(ret, dfs(r + 1, c) + map[r][c]);
    ret = max(ret, dfs(r, c + 1) + map[r][c]);
    ret = max(ret, dfs(r + 1, c + 1) + map[r][c]);

    return ret;
}

int main()
{
    cin >> n >> m;

    memset(cache, -1, sizeof(cache));
    map.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> map[i][j];
        }
    }

    dfs(1, 1);

    cout << cache[1][1] << '\n';

    return 0;
}