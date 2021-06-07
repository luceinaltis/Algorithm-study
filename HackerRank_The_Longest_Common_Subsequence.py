# Time Complexity : O(nm)
def LongestCommonSubsequence(arrA, arrB):
    n = len(arrA) - 1
    m = len(arrB) - 1

    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        for j in range(m + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif arrA[i] == arrB[j]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    lcs = []
    i, j = n, m
    while True:
        if dp[i][j] == dp[i][j-1]:
            j -= 1
        elif dp[i][j] == dp[i-1][j]:
            i -= 1
        else:
            lcs.append(arrB[j])
            i -= 1
            j -= 1

        if i == 0 or j == 0:
            break
    lcs.reverse()

    return lcs


if __name__ == '__main__':
    n, m = list(map(int, input().split()))

    arrA = list(map(int, input().split()))
    arrB = list(map(int, input().split()))
    arrA.insert(0, 0)
    arrB.insert(0, 0)

    lcs = LongestCommonSubsequence(arrA, arrB)

    for i in lcs:
        print(i, end=' ')
    print()
