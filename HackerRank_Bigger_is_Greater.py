def getNextString(w):
    w = list(w)
    for i in reversed(range(1, len(w))):
        if w[i-1] < w[i]:
            # w[i-1]
            l = i - 1
            r = i
            for j in range(i, len(w)):
                if w[r] > w[j] and w[j] > w[i - 1]:
                    r = j
            w[l], w[r] = w[r], w[l]

            w[i:] = sorted(w[i:])
            break

    return ''.join(w)


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        w = input()

        nextW = getNextString(w)
        if w == nextW:
            print('no answer')
        else:
            print(nextW)
