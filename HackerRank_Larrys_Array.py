import copy


def getSorted(arr):
    arr = copy.deepcopy(arr)
    for _ in range(1000):
        for idx, val in enumerate(arr[:-2]):
            for _ in range(4):
                arr[idx:idx+2], arr[idx+2] = arr[idx+1:idx+3], arr[idx]
                if arr[idx] < arr[idx+1] and arr[idx] < arr[idx+2]:
                    break
    return arr


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))

        if sorted(arr) == getSorted(arr):
            print('YES')
        else:
            print('NO')
