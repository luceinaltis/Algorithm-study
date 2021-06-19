# return: lower bound index of value
def lowerBound(x, val):
    l = 0
    r = len(x)
    while l < r:
        mid = (l+r)//2
        if x[mid] < val:
            l = mid + 1
        else:
            r = mid
    return l


def getMinTransmitters(x, n, k):
    installCnt = 0
    idx = 0
    while idx < len(x):
        installIndex = lowerBound(x, x[idx]+k+1) - 1
        installCnt += 1

        nextIdx = lowerBound(x, x[installIndex]+k+1)
        idx = nextIdx
    return installCnt


if __name__ == '__main__':
    n, k = list(map(int, input().split()))
    x = list(map(int, input().split()))
    x.sort()

    minCnt = getMinTransmitters(x, n, k)

    print(minCnt)
