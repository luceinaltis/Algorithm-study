#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> timeValue;
vector<int> minTime;

// tmp에서 시작해보자.
void dfs(int tmp, int minBuildTime)
{
    if (minTime[tmp] < minBuildTime)
    {
        minTime[tmp] = minBuildTime;
    }

    for (int i = 0; i < adj[tmp].size(); ++i)
    {
        int nextVertex = adj[tmp][i];

        if (minTime[nextVertex] < minBuildTime + timeValue[nextVertex])
        {
            dfs(nextVertex, minBuildTime + timeValue[nextVertex]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    adj.assign(n + 1, vector<int>());
    timeValue.assign(n + 1, 0);
    minTime.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        int next;
        cin >> timeValue[i];

        while (true)
        {
            cin >> next;

            if (next == -1)
                break;

            adj[next].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (minTime[i] < timeValue[i])
        {
            dfs(i, timeValue[i]);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << minTime[i] << '\n';
    }

    return 0;
}