

if __name__ == '__main__':
    h, w = list(map(int, input().split()))
    area = []
    for _ in range(h):
        row = list(map(int, input().split()))
        area.append(row)

    top = h*w
    bottom = h*w
    left = 0
    right = 0
    up = 0
    down = 0
    for i in range(h):
        for j in range(w):
            if j == 0:
                left += area[i][j]
            else:
                left += max(0, area[i][j] - area[i][j-1])

            if j == w - 1:
                right += area[i][j]
            else:
                right += max(0, area[i][j] - area[i][j+1])

    for j in range(w):
        for i in range(h):
            if i == 0:
                up += area[i][j]
            else:
                up += max(0, area[i][j] - area[i-1][j])

            if i == h - 1:
                down += area[i][j]
            else:
                down += max(0, area[i][j] - area[i+1][j])

    print(top+bottom+left+right+up+down)
