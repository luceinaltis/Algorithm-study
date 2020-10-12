#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    adj.assign(n+1, vector<int>());

    // adj, visited를 초기화시키자.
    visited.assign(n+1, 0);
    for(int i = 0; i < edge.size(); ++i)
    {
        int a = edge[i][0];        
        int b = edge[i][1];   
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> que;

    que.push(1);
    visited[1] = 1;

    // 1로부터 시작해서 간선의 크기를 1씩 늘려 탐색해보자.
    while(!que.empty())
    {
        int queSize = que.size();
        answer = queSize;

        for(int i = 0; i < queSize; ++i) 
        {
            int tmpNode = que.front(); que.pop();

            for(int next = 0; next < adj[tmpNode].size(); ++next)
            {
                int nextNode = adj[tmpNode][next];
                if(!visited[nextNode]) 
                {
                    visited[nextNode] = 1;
                    que.push(nextNode);
                }
            }
        }
    }
    
    return answer;
}