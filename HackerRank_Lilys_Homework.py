import copy


def getMinimumSwap(originalArr, sortedArr):
    cnt = 0
    originalPos = {val: idx for idx, val in enumerate(originalArr)}
    originalArr = copy.deepcopy(originalArr)
    for idx, val in enumerate(originalArr):
        if val == sortedArr[idx]:
            continue
        originalArr[idx], originalArr[originalPos[sortedArr[idx]]
                                      ] = originalArr[originalPos[sortedArr[idx]]], originalArr[idx]
        originalPos[val], originalPos[sortedArr[idx]
                                      ] = originalPos[sortedArr[idx]], originalPos[val]
        cnt += 1

    return cnt


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    ascendArr = sorted(arr)
    descendArr = sorted(arr, reverse=True)
    minimumSwap = min(getMinimumSwap(arr, ascendArr),
                      getMinimumSwap(arr, descendArr))

    print(minimumSwap)
