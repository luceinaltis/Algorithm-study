from collections import defaultdict
import subprocess


def getTwoIceCream(m, n, arr):
    dic = defaultdict(lambda: [0, []])

    for idx, val in enumerate(arr):
        dic[val][0] += 1
        dic[val][1].append(idx + 1)

    if m % 2 == 0 and dic[m//2][0] >= 2:
        return [dic[m//2][1][0], dic[m//2][1][1]]

    for i in arr:
        if m-i != i and dic[m - i][0] > 0:
            return [dic[m - i][1][0], dic[i][1][0]]
        elif m - i == i and dic[m-i][0] >= 2:
            return [dic[m - i][1][0], dic[i][1][1]]

    # There is not impossible case
    return [-1, -1]


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        m = int(input())
        n = int(input())

        arr = list(map(int, input().split()))

        a, b = getTwoIceCream(m, n, arr)

        if a > b:
            a, b = b, a
        print(f'{a} {b}')
