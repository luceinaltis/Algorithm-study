import sys
sys.setrecursionlimit(10**7)

# using memoization
# 0, not possible
# 1, possible


def isPossible(memoization, stringA, stringB, i, j):
    if j == len(stringB):
        for pos in range(i, len(stringA)):
            if stringA[pos].isupper():
                return 0
        return 1
    if i == len(stringA):
        return 0

    ret = memoization[i][j]
    if ret != -1:
        return ret

    # searching tree
    memoization[i][j] = 0
    if stringA[i].islower():
        if stringA[i].upper() == stringB[j]:
            if isPossible(memoization, stringA, stringB, i+1, j+1) or isPossible(memoization, stringA, stringB, i+1, j):
                memoization[i][j] = 1
        else:
            if isPossible(memoization, stringA, stringB, i+1, j):
                memoization[i][j] = 1
    elif stringA[i].isupper():
        if stringA[i].upper() == stringB[j]:
            if isPossible(memoization, stringA, stringB, i+1, j+1):
                memoization[i][j] = 1
        else:
            memoization[i][j] = 0

    return memoization[i][j]


if __name__ == '__main__':
    q = int(input())

    for _ in range(q):
        stringA = input()
        stringB = input()

        memoization = [[-1] * len(stringB) for _ in range(len(stringA))]
        if isPossible(memoization, stringA, stringB, 0, 0):
            print('YES')
        else:
            print('NO')
