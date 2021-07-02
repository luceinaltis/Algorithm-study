def getLongestCommonSubsequence(a, b, c):
    l = len(a)
    m = len(b)
    n = len(c)
    dp = [[[0 for _ in range(n+1)] for _ in range(m+1)] for _ in range(l+1)]

    for i in range(1, l+1):
        for j in range(1, m+1):
            for k in range(1, n+1):
                if a[i-1] == b[j-1] and b[j-1] == c[k-1]:
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                else:
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i]
                                      [j-1][k], dp[i][j][k-1])

    lcs = []
    while l > 0 and m > 0 and n > 0:
        if a[l-1] == b[m-1] and b[m-1] == c[n-1]:
            lcs.append(a[l-1])
            l -= 1
            m -= 1
            n -= 1
        else:
            if dp[l][m][n] == dp[l][m][n-1]:
                n -= 1
            elif dp[l][m][n] == dp[l][m-1][n]:
                m -= 1
            elif dp[l][m][n] == dp[l-1][m][n]:
                l -= 1
    lcs.reverse()

    return ''.join(lcs)


if __name__ == '__main__':
    str1 = input()
    str2 = input()
    str3 = input()

    lcs = getLongestCommonSubsequence(str1, str2, str3)

    print(len(lcs))
