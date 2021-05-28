def union(parent, rank, u, v):
    u = find(parent, u)
    v = find(parent, v)

    if u == v:
        return

    if rank[u] < rank[v]:
        temp = u
        u = v
        v = temp

    parent[v] = u

    if rank[u] == rank[v]:
        rank[u] += 1

    return


def find(parent, x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent, parent[x])
        return parent[x]


def main():
    n, p = list(map(int, input().split(' ')))
    parent = [i for i in range(n)]
    rank = [1] * n

    for i in range(p):
        a, b = list(map(int, input().split(' ')))
        union(parent, rank, a, b)

    # Time Complexity : O(n*logn)
    dic = {}
    for i in range(n):
        setNum = find(parent, i)
        if setNum in dic:
            dic[setNum] += 1
        else:
            dic[setNum] = 1

    ans = 0
    for key in dic.values():
        ans += key * (n - key)
    ans //= 2

    print(ans)

    return 0


main()
