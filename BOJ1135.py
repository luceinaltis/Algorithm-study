def dp(adj, node, n):
    ret = 0
    childTime = []
    for childNode in range(n):
        if adj[node][childNode] == 1:
            childTime.append(dp(adj, childNode, n))
    childTime.sort()
    childTime.reverse()

    for idx, val in enumerate(childTime):
        ret = max(ret, val + idx + 1)

    return ret


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    adj = [[0] * n for _ in range(n)]
    for idx, val in enumerate(arr):
        if val != -1:
            adj[val][idx] = 1

    print(dp(adj, 0, n))
