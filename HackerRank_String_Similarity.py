def getZArray(s):
    strLen = len(s)
    z = [0]*strLen
    z[0] = strLen

    l = -1
    r = -1
    for i in range(1, strLen):
        if r < i:
            l = i
            r = i
            while r < strLen and s[r] == s[r - l]:
                r += 1
            z[l] = r - l
            r -= 1
        else:
            k = i - l
            if z[k] < r - i + 1:
                z[i] = z[k]
            else:
                l = i
                while r < strLen and s[r] == s[r-l]:
                    r += 1
                z[i] = r - l
                r -= 1

    ansSum = 0
    for i in z:
        ansSum += i

    return ansSum


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ansSum = getZArray(s)

        print(ansSum)
