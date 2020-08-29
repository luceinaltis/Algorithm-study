#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX_V 52
using namespace std;

const int INF = 987654321;

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink)
{
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;

    while(true)
    {
        vector<int> parent(MAX_V, -1);
        queue<int> que;

        que.push(source);

        while(!que.empty() && parent[sink] == -1)
        {
            int here = que.front(); que.pop();
            for(int there = 0; there < MAX_V; ++there)
            {
                // 잔여 용량이 남아 있는 간선을 따라 탐색한다.
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    que.push(there);
                    parent[there] = here;
                }
            }

        }
        if(parent[sink] == -1) break;

        int amount = INF;
        for(int p = sink; p != source; p = parent[p])
        {
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }

        for(int p = sink; p != source; p = parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        totalFlow += amount;
    }
    return totalFlow;
    
}

// 현재 char값에 해당하는 노드번호를 반환해주자.
// 0 ~ 25 : 'A' ~ 'Z'
// 26 ~ 51 : 'a' ~ 'z'
int getNode(const char ch)
{
    int isUpper = 0;
    if('A' <= ch && ch <= 'Z') isUpper = 1;
    else if('a' <= ch && ch <= 'z') isUpper = 0;
    else return -1;

    if(isUpper)
    {
        return ch - 'A';
    }
    else
    {
        return ch - 'a' + 26;
    }
}

int main()
{
    int n;

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int capa;
        char a, b;

        cin >> a >> b >> capa;

        int indexA = getNode(a);
        int indexB = getNode(b);

        capacity[indexA][indexB] += capa;
        capacity[indexB][indexA] += capa;
    }

    cout << networkFlow(0, 25) << '\n';

    return 0;
}