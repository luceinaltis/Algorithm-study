from collections import deque


def bfs(mp, r, c, x, y, visited):
    # right up, right, right down
    dirX = [-1, 0, 1]
    dirY = [1, 1, 1]

    que = deque()
    # initialization
    que.append((x, y))

    while que:
        tmpX, tmpY = que.pop()

        mp[tmpX][tmpY] = 'x'
        visited[tmpX][tmpY] = 1

        if tmpY == c-1:
            return 1

        for i in reversed(range(3)):
            nextX = tmpX + dirX[i]
            nextY = tmpY + dirY[i]

            if nextX < 0 or nextX >= r:
                continue
            if nextY < 0 or nextY >= c:
                continue

            if mp[nextX][nextY] == '.' and visited[nextX][nextY] == 0:
                que.append((nextX, nextY))
    return 0


if __name__ == '__main__':
    r, c = list(map(int, input().split()))
    visited = [[0]*c for _ in range(r)]

    mp = []
    for _ in range(r):
        row = list(input())
        mp.append(row)

    ans = 0
    for i in range(r):
        ans += bfs(mp, r, c, i, 0, visited)
    print(ans)
