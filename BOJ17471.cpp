#include <iostream>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;

int n;
int ans = INF;

vector<int> population;
vector<vector<int>> adj;
int visited;

int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

// 첫번째 선거구 0, 두번째 선거구 1로 생각하자
void dfs(int here, int color, const int &set)
{
    for (int next = 0; next < adj[here].size(); ++next)
    {
        int nextNode = adj[here][next];
        // 방문하지 않았을때
        // 같은 선거구일 경우만 탐색
        if ((visited & (1 << nextNode)) == 0 && (((set & (1 << nextNode)) > 0 ? 1 : 0) == color))
        {
            // 방문했다고 체크하자
            visited |= (1 << nextNode);
            dfs(nextNode, color, set);
        }
    }
}

// 들어온 집합을 토대로 가능한지 아닌지를 판단한다.
// 가능하다면 인구차이의 최솟값을 반환한다.
// 가능하지 않다면 INF을 반환하자.
int calculation(const int &set)
{
    // 방문여부 초기화
    visited = 0;

    // 첫번째 선거구, 두번째 선거구 탐색여부
    int first = 0;
    int second = 0;
    for (int i = 1; i <= n; ++i)
    {
        // 방문하지 않은 구역이라면 방문하자
        if ((visited & (1 << i)) == 0)
        {
            if (first && ((set & (1 << i)) == 0))
                continue;
            if (second && ((set & (1 << i)) > 0))
                continue;

            // 선거구 탐색 여부 기록
            if ((set & (1 << i)) > 0)
            {
                second = 1;
            }
            else
            {
                first = 1;
            }
            visited |= (1 << i);
            dfs(i, (set & (1 << i)) > 0 ? 1 : 0, set);
        }
    }

    // 모든 선거구를 방문했다면?
    // 가능한 경우이니 인구최솟값을 반환하자.
    if (visited == ((1 << (n + 1)) - 2))
    {
        int a = 0;
        int b = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (((1 << i) & set) > 0)
            {
                // 두번째 선거구
                a += population[i];
            }
            else
            {
                // 첫번째 선거구
                b += population[i];
            }
        }

        return abs(a - b);
    }
    else
    {
        return INF;
    }
}

void bf(int tmp, int set)
{
    // 기저사례
    if (tmp == n + 1)
    {
        ans = min(ans, calculation(set));
        return;
    }

    // 탐색
    bf(tmp + 1, (set | (1 << tmp)));
    bf(tmp + 1, set);
}

int main()
{

    cin >> n;

    population.assign(n + 1, 0);
    adj.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; ++i)
    {
        cin >> population[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        int size;

        cin >> size;

        for (int j = 0; j < size; ++j)
        {
            int tmp;
            cin >> tmp;
            adj[i].push_back(tmp);
        }
    }

    bf(1, 0);

    if (ans == INF)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}