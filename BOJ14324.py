import copy
from collections import deque


def delBfs(w, visited, x, y, r, c):
    dirX = [-1, 0, 1, 0]
    dirY = [0, 1, 0, -1]

    que = deque()
    que.append((x, y))

    while que:
        tmpX, tmpY = que.popleft()
        visited[tmpX][tmpY] = 0

        for i in range(4):
            nextX = tmpX + dirX[i]
            nextY = tmpY + dirY[i]

            if nextX < 0 or nextX >= r:
                continue
            if nextY < 0 or nextY >= c:
                continue

            if visited[nextX][nextY] == 1 and w[nextX][nextY] == w[tmpX][tmpY]:
                que.append((nextX, nextY))


# if set of cell outside of that area is higher than itself, return 1 or not -1
def bfs(w, visited, x, y, r, c):
    # up, right, down, left
    dirX = [-1, 0, 1, 0]
    dirY = [0, 1, 0, -1]

    que = deque()
    que.append((x, y))
    minimumVal = 987654321

    while que:
        tmpX, tmpY = que.popleft()
        visited[tmpX][tmpY] = 1

        for i in range(4):
            nextX = tmpX + dirX[i]
            nextY = tmpY + dirY[i]

            if nextX < 0 or nextX >= r:
                delBfs(w, visited, nextX, nextY, r, c)
                return
            if nextY < 0 or nextY >= c:
                delBfs(w, visited, nextX, nextY, r, c)
                return

            if w[nextX][nextY] < w[tmpX][tmpY]:
                visited[nextX][nextY] = 1
                delBfs(w, visited, nextX, nextY, r, c)
                return
            elif w[nextX][nextY] != w[tmpX][tmpY]:
                minimumVal = min(minimumVal, w[nextX][nextY])

            if visited[nextX][nextY] == 0 and w[nextX][nextY] == w[tmpX][tmpY]:
                que.append((nextX, nextY))

    que.append((x, y))
    while que:
        tmpX, tmpY = que.popleft()
        w[tmpX][tmpY] = minimumVal

        for i in range(4):
            nextX = tmpX + dirX[i]
            nextY = tmpY + dirY[i]

            if nextX < 0 or nextX >= r:
                delBfs(w, visited, nextX, nextY, r, c)
                return
            if nextY < 0 or nextY >= c:
                delBfs(w, visited, nextX, nextY, r, c)
                return

            if w[nextX][nextY] == w[tmpX][tmpY]:
                que.append((nextX, nextY))

            if w[nextX][nextY] < w[tmpX][tmpY]:
                visited[nextX][nextY] = 1
                delBfs(w, visited, nextX, nextY, r, c)
                return


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        r, c = list(map(int, input().split()))
        visited = [[0] * c for _ in range(r)]

        mp = []
        for _ in range(r):
            row = list(map(int, input().split()))
            mp.append(mp)
        w = copy.deepcopy(mp)
