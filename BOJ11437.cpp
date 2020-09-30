#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> depth, parent;

// 각 노드의 깊이와 부모 노드를 저장해주는 전처리
// O(N)
void dfs(int currentNode, int currentDepth)
{
    depth[currentNode] = currentDepth;
    for(int next : adj[currentNode])
    {
        // depth가 방문 여부를 판단해준다.
        // 아직 방문하지 않았다면 -1이다
        if(depth[next] == -1)
        {
            parent[next] = currentNode;
            dfs(next, currentDepth+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;

    cin >> n;
    
    adj.assign(n+1, vector<int>());
    depth.assign(n+1, -1);
    parent.assign(n+1, 0);

    for(int i = 0; i < n - 1; ++i)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cin >> m;

    // 시간복잡도 O(M * N)
    for(int i = 0; i < m; ++i)
    {
        // 입력받은 a와 b의 최소 공통 조상을 구하자.
        int a, b;

        cin >> a >> b;

        // 코드를 줄이기 위해 a를 깊이가 더 깊은 노드로 두자.
        if(depth[a] < depth[b]) swap(a, b);

        // a와 b의 깊이를 맞추기 위해 a의 부모를 찾아가자.
        while(depth[a] != depth[b]) a = parent[a];

        // a와 b의 깊이가 똑같아지면 같은 부모가 나올때까지 찾자.
        while(a != b)
        {
            a = parent[a];
            b = parent[b];
        }

        cout << a << '\n';
    }

    return 0;
}