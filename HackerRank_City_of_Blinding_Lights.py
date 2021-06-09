from copy import deepcopy

CONST_INF = 987654321


def floyd(adj, n):
    global CONST_INF

    minDist = deepcopy(adj)
    for i in range(n+1):
        for j in range(n+1):
            if i == j:
                minDist[i][j] = 0
            if minDist[i][j] == -1:
                minDist[i][j] = CONST_INF

    for mid in range(1, n+1):
        for start in range(1, n+1):
            for end in range(1, n+1):
                if minDist[start][end] > minDist[start][mid] + minDist[mid][end]:
                    minDist[start][end] = minDist[start][mid] + \
                        minDist[mid][end]
    return minDist


if __name__ == '__main__':
    n, m = list(map(int, input().split()))
    adj = [[-1]*(n + 1) for _ in range(n + 1)]
    for i in range(m):
        u, v, w = list(map(int, input().split()))
        adj[u][v] = w

    minDist = floyd(adj, n)

    q = int(input())

    for i in range(q):
        qFrom, qTo = list(map(int, input().split()))
        if minDist[qFrom][qTo] == CONST_INF:
            print(-1)
        else:
            print(minDist[qFrom][qTo])
