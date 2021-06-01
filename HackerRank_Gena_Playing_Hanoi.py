from collections import deque


def getTopDisks(state, n):
    # 5 : not disks
    topDisks = [-1 for i in range(4)]
    for i in range(n):
        disk = i
        rod = (state >> (2*i)) & 0b11
        if topDisks[rod] > disk or topDisks[rod] == -1:
            topDisks[rod] = disk

    return topDisks


def getInitialBitmap(posts):
    bitmap = 0
    n = len(posts)
    for i in range(n):
        bitmap |= ((posts[i] - 1) << (i*2))
    return bitmap


def minMoves(posts):
    N = 4
    n = len(posts)
    initBitmapState = getInitialBitmap(posts)
    visited = set()

    step = 0
    dq = deque()

    if initBitmapState == 0:
        return 0

    dq.append(initBitmapState)
    visited.add(initBitmapState)
    while dq:
        k = len(dq)
        step += 1
        for i in range(k):
            tmpState = dq.popleft()

            topDisks = getTopDisks(tmpState, n)
            for i in range(N):
                fromTopDisk = topDisks[i]
                if fromTopDisk != -1:
                    for j in range(N):
                        toTopDisk = topDisks[j]
                        if i != j and (fromTopDisk < toTopDisk or toTopDisk == -1):
                            newState = tmpState
                            newState &= (~(0b11 << (fromTopDisk*2)))
                            newState |= (j << (fromTopDisk*2))
                            if newState not in visited:
                                if newState == 0:
                                    return step
                                dq.append(newState)
                                visited.add(newState)


def main():
    n = int(input())
    posts = list(map(int, input().split()))

    print(minMoves(posts))

    return 0


main()
