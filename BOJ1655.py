import heapq
import sys

if __name__ == '__main__':
    n = int(input())
    lowerPQ = []
    upperPQ = []

    for _ in range(n):
        num = int(sys.stdin.readline())
        size = len(lowerPQ) + len(upperPQ)

        if size == 0:
            heapq.heappush(lowerPQ, (-num, num))
            sys.stdout.write(f'{num}\n')
            continue
        else:
            lo = lowerPQ[0][1]

            if lo < num:
                heapq.heappush(upperPQ, (num, num))
            else:
                heapq.heappush(lowerPQ, (-num, num))

            # upper to lower
            if len(lowerPQ) < len(upperPQ):
                element = heapq.heappop(upperPQ)[1]
                heapq.heappush(lowerPQ, (-element, element))

            # lower to upper
            if len(lowerPQ) > len(upperPQ) + 1:
                element = heapq.heappop(lowerPQ)[1]
                heapq.heappush(upperPQ, (element, element))

            mid = lowerPQ[0][1]
            sys.stdout.write(f'{mid}\n')
