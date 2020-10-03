#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> isRoot;

// 각 노드 사이에 어떤 노드들이 있는지 저장한 배열
// 중위순회를 통해 저장하자.
int index = 1;
vector<int> arr;

int n;

void preCalc(int node)
{
    visited.assign(n+1, 0);

    int left = adj[node][0];
    int right = adj[node][1];

    if(left != -1) preCalc(left);
    arr[node] = index++;
    if(right != -1) preCalc(right);
}

void bfs(int root)
{
    queue<int> que;

    int maxLevel, maxWidth = 0;
    int tmpLevel = 0;

    visited.assign(n+1, 0);
    // 초기화
    // 루트를 집어넣자
    que.push(root);
    visited[root] = 1;

    while(!que.empty())
    {
        tmpLevel += 1;

        // bfs로 돌면서 각 레벨을 탐색하자.
        int k = que.size();
        int mostLeft, mostRight;

        // 각 레벨의 크기만큼 탐색하자.
        for(int i = 0; i < k; ++i)
        {
            int node = que.front();
            que.pop();

            // 자식 노드들을 집어넣자.
            for(int next = 0; next < adj[node].size(); next++)
            {
                int nextNode = adj[node][next];
                if(visited[nextNode] == 0 && nextNode != -1)
                {
                    visited[nextNode] = 1;
                    que.push(nextNode);
                }
            }
            // 이 레벨에서 가장 왼쪽 노드와 가장 오른쪽 노드를 구하자.
            if(i == 0) mostLeft = node;
            if(i == k - 1) mostRight = node;
        }

        int tmpWidth = arr[mostRight] - arr[mostLeft] + 1; 
        if(maxWidth < tmpWidth)
        {
            maxWidth = tmpWidth;
            maxLevel = tmpLevel;
        }            
    }

    cout << maxLevel << ' ' << maxWidth << '\n';
}

int main()
{
    cin >> n;

    int root;
    adj.assign(n+1, vector<int>());
    arr.assign(n+1, 0);
    isRoot.assign(n+1, 1);

    for(int i = 0; i < n; ++i)
    {
        int node, left, right;

        cin >> node >> left >> right;

        adj[node].push_back(left);
        adj[node].push_back(right);

        if(left != -1) isRoot[left] = 0;
        if(right != -1) isRoot[right] = 0;
    }

    // root를 찾아서 집어넣자..

    for(int i = 1; i <= n; ++i)
    {
        if(isRoot[i] == 1)
        {
            root = i;
            break;
        }
    }
    preCalc(root);
    bfs(root);

    return 0;
}