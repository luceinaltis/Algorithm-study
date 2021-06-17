def getMedian(count, d):
    mid = d // 2
    l = 0
    r = -1
    median = 0
    # odd
    for idx, val in enumerate(count):
        l = r + 1
        r += val

        if l <= mid and mid <= r:
            median = idx
            break

    if d % 2 == 0:
        # even
        l = 0
        r = -1
        for idx, val in enumerate(count):
            l = r + 1
            r += val

            if l <= (mid+1) and (mid+1) <= r:
                median += idx
                median /= 2
                break
    return median


def getFraudNotificationCount(n, d, expenditure):
    count = [0] * 201
    notiCnt = 0

    for idx, val in enumerate(expenditure[:-1]):
        count[val] += 1
        if idx - d >= 0:
            count[expenditure[idx - d]] -= 1
        if idx + 1 - d >= 0:
            median = getMedian(count, d)
            if 2*median <= expenditure[idx+1]:
                notiCnt += 1
    return notiCnt


if __name__ == '__main__':
    n, d = list(map(int, input().split()))

    expenditure = list(map(int, input().split()))

    cnt = getFraudNotificationCount(n, d, expenditure)
    print(cnt)
