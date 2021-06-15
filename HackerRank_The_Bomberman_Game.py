import copy


def downtimeBombs(grid, r, c):
    for x in range(r):
        grid[x] = grid[x].replace('1', '0')
        grid[x] = grid[x].replace('2', '1')
        grid[x] = grid[x].replace('3', '2')
    return grid


def detonateBombs(grid, r, c):
    # up, right, down, left
    dirX = [-1, 0, 1, 0]
    dirY = [0, 1, 0, -1]

    # test

    grid = [list(i) for i in grid]

    for x in range(r):
        for y in range(c):
            if grid[x][y] == '0':
                grid[x][y] = '.'
                for i in range(4):
                    nextX = x + dirX[i]
                    nextY = y + dirY[i]

                    if nextX < 0 or r <= nextX:
                        continue
                    if nextY < 0 or c <= nextY:
                        continue
                    if grid[nextX][nextY] != '0':
                        grid[nextX][nextY] = '.'

    grid = [''.join(i) for i in grid]

    return grid


def plantBombs(grid, r, c):
    for i in range(r):
        grid[i] = grid[i].replace('.', '3')

    return grid


if __name__ == '__main__':
    r, c, n = list(map(int, input().split()))

    grid = []
    for _ in range(r):
        grid.append(input().replace('O', '3'))
    time = 1
    grid = downtimeBombs(grid, r, c)

    phase = dict()
    phase['1'] = copy.deepcopy(grid)
    while time <= 5:
        # 3
        grid = downtimeBombs(grid, r, c)
        grid = plantBombs(grid, r, c)
        time += 1
        phase[f'{time}'] = copy.deepcopy(grid)
        # 4
        grid = downtimeBombs(grid, r, c)
        grid = detonateBombs(grid, r, c)
        time += 1
        phase[f'{time}'] = copy.deepcopy(grid)

    if n == 1:
        grid = phase['1']
    elif n % 2 == 0:
        grid = phase['2']
    elif n % 4 == 3:
        grid = phase['3']
    elif n % 4 == 1:
        grid = phase['5']
    for i in range(r):
        print(grid[i].replace('3', 'O').replace('2', 'O').replace('1', 'O'))
