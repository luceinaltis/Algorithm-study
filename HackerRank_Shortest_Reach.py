import heapq


def dijkstra(nodesNum, adj, startNode):
    CONST_INF = 987654321
    visited = [0] * (nodesNum + 1)
    minDistList = [CONST_INF] * (nodesNum + 1)

    hq = []
    # init
    heapq.heappush(hq, (0, startNode))
    while hq:
        minDistNode = heapq.heappop(hq)

        if visited[minDistNode[1]]:
            continue
        visited[minDistNode[1]] = 1

        for nextNode in range(1, nodesNum + 1):
            if adj[minDistNode[1]][nextNode] and minDistList[nextNode] > minDistNode[0] + 6:
                minDistList[nextNode] = minDistNode[0] + 6
                heapq.heappush(hq, (minDistList[nextNode], nextNode))

    minDistList = [-1 if i == CONST_INF else i for i in minDistList]

    return minDistList


def main():
    q = int(input())
    for _ in range(q):
        n, m = list(map(int, input().split()))
        adj = [[0]*(n+1) for _ in range(n+1)]

        for i in range(m):
            u, v = list(map(int, input().split()))
            adj[u][v] = 1
            adj[v][u] = 1

        startNode = int(input())
        minDistList = dijkstra(n, adj, startNode)

        for i in range(1, n + 1):
            if i == startNode:
                continue
            print(minDistList[i], end=' ')
        print('')

    return 0


main()
