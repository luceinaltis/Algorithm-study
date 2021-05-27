import queue


def calculate(matrix):
    n = len(matrix)
    m = len(matrix[0])
    visited = [[0]*m for i in range(n)]

    maxRegion = 0
    for i in range(n):
        for j in range(m):
            if visited[i][j] == 0 and matrix[i][j] == 1:
                maxRegion = max(maxRegion, bfs(matrix, i, j, visited))

    return maxRegion


def bfs(matrix, x, y, visited):
    # [up, upright, right, downright, down, leftdown, left, leftup]
    dirX = [-1, -1, 0, 1, 1, 1, 0, -1]
    dirY = [0, 1, 1, 1, 0, -1, -1, -1]

    n = len(matrix)
    m = len(matrix[0])

    que = queue.Queue()
    que.put({'x': x, 'y': y})
    visited[x][y] = 1
    size = 0
    while not que.empty():
        tmp = que.get()
        size += 1

        tmpX = tmp['x']
        tmpY = tmp['y']
        # Find next step
        for i in range(len(dirX)):
            nextX = tmpX + dirX[i]
            nextY = tmpY + dirY[i]

            # If it's out of range, continue
            if nextX < 0 or n <= nextX:
                continue
            if nextY < 0 or m <= nextY:
                continue

            if matrix[nextX][nextY] == 1 and visited[nextX][nextY] == 0:
                que.put({'x': nextX, 'y': nextY})
                visited[nextX][nextY] = 1

    return size


def main():
    n = int(input())
    m = int(input())

    matrix = []
    for x in range(n):
        row = list(map(int, input().split(' ')))
        matrix.append(row)

    print(calculate(matrix))

    return 0


main()
