import heapq


def getMinimumCost(k, arr):
    pq = []

    cost = 0
    for i in arr:
        heapq.heappush(pq, i)

    while len(pq) > 1:

        minVal1 = heapq.heappop(pq)
        minVal2 = heapq.heappop(pq)
        cost += (minVal1 + minVal2)

        heapq.heappush(pq, minVal1 + minVal2)

    return cost


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        k = int(input())
        arr = list(map(int, input().split()))

        minCost = getMinimumCost(k, arr)

        print(minCost)
