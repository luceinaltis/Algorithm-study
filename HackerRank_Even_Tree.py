def dfs(visited, adj, nodesNum, tmp):
    count = 1
    visited[tmp] = 1
    for i in range(1, nodesNum+1):
        if adj[tmp][i] == 1 and visited[i] == 0:
            count += dfs(visited, adj, nodesNum, i)

    return count


def main():
    nodesNum, edgesNum = list(map(int, input().split()))
    adj = [[0]*(nodesNum+1) for i in range(nodesNum+1)]
    for i in range(edgesNum):
        u, v = list(map(int, input().split()))
        adj[u][v] = 1
        adj[v][u] = 1

    ans = 0
    for i in range(1, nodesNum + 1):
        visited = [0] * (nodesNum + 1)

        visited[i] = 1
        for j in range(1, nodesNum + 1):
            if adj[i][j] and dfs(visited, adj, nodesNum, j) % 2 == 0:
                ans += 1
                adj[i][j] = 0
                adj[j][i] = 0
    print(ans)

    return 0


main()
