import copy

CONST_INF = 987654321


def printIsPossible(n, arr):
    global CONST_INF
    originalArr = copy.deepcopy(arr)
    sortedArr = sorted(originalArr)

    l = CONST_INF
    r = 0
    for i, v in enumerate(originalArr):
        if v == sortedArr[i]:
            canPart = True
            continue
        l = min(l, i)
        r = max(r, i)

    swapedArr = copy.deepcopy(originalArr)
    swapedArr[l], swapedArr[r] = swapedArr[r], swapedArr[l]
    reversedArr = copy.deepcopy(originalArr)
    reversedArr[l:r+1] = reversed(reversedArr[l:r+1])

    if swapedArr == sortedArr:
        print('yes')
        print(f'swap {l+1} {r+1}')
    elif reversedArr == sortedArr:
        print('yes')
        print(f'reverse {l+1} {r+1}')
    else:
        print('no')


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    printIsPossible(n, arr)
