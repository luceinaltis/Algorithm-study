import heapq


def prim(adj, n, start):
    minWeight = 0
    visited = [0] * (n + 1)

    # (w, u, v)
    hq = []
    # init
    visited[start] = 1
    for nextNode in range(1, n + 1):
        if adj[start][nextNode] >= 0 and visited[nextNode] == 0:
            heapq.heappush(hq, (adj[start][nextNode], start, nextNode))
    while hq:
        w, u, v = heapq.heappop(hq)
        if visited[v] == 1:
            continue
        visited[v] = 1
        minWeight += w
        for nextNode in range(1, n + 1):
            if adj[v][nextNode] >= 0 and visited[nextNode] == 0:
                heapq.heappush(hq, (adj[v][nextNode], v, nextNode))

    return minWeight


def main():
    n, m = list(map(int, input().split()))
    adj = [[-1]*(n+1) for _ in range(n + 1)]
    for _ in range(m):
        u, v, w = list(map(int, input().split()))
        if adj[u][v] > w or adj[u][v] == -1:
            adj[u][v] = w
            adj[v][u] = w

    start = int(input())

    minWeight = prim(adj, n, start)
    print(minWeight)

    return 0


main()
