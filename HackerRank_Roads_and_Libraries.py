def union(u, v, rank, parent):
    u = find(u, rank, parent)
    v = find(v, rank, parent)

    # If u and v are on same set, get out
    if u == v:
        return

    if rank[u] < rank[v]:
        u, v = v, u

    parent[v] = u

    if rank[u] == rank[v]:
        rank[u] += 1


def find(x, rank, parent):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x], rank, parent)
        return parent[x]


# Return value : Minimum cost of building libraries
def kruskal(canBuildRoads, cRoad, cLib, n):
    minCost = 0
    if cRoad < cLib:
        rank = [1] * (n + 1)
        parent = [i for i in range(0, n + 1)]

        for [u, v] in canBuildRoads:
            if find(u, rank, parent) != find(v, rank, parent):
                minCost += cRoad
                union(u, v, rank, parent)

        isRoot = [0] * (n + 1)
        for i in range(1, n+1):
            setNum = find(i, rank, parent)
            if isRoot[setNum] == 0:
                minCost += cLib
                isRoot[setNum] = 1
    else:
        minCost = cLib * n

    return minCost


if __name__ == '__main__':
    q = int(input())

    for _ in range(q):
        n, m, cLib, cLoad = list(map(int, input().split()))

        canBuildRoads = []
        for _ in range(m):
            u, v = list(map(int, input().split()))
            canBuildRoads.append([u, v])

        minCost = kruskal(canBuildRoads, cLoad, cLib, n)
        print(minCost)
