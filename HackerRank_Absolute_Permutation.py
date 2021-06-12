# greedy algorithm
if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n, k = list(map(int, input().split()))

        pos = [0] * (n + 1)

        isPossible = True
        for i in reversed(range(1, n+1)):
            if pos[i] == 0:
                if i - k > 0 and pos[i - k] == 0:
                    pos[i - k] = i
                elif i + k <= n and pos[i + k] == 0:
                    pos[i + k] = i
                else:
                    isPossible = False
                    break
            else:
                if i + k <= n and pos[i + k] == 0:
                    pos[i + k] = i
                elif i - k > 0 and pos[i - k] == 0:
                    pos[i - k] = i
                else:
                    isPossible = False
                    break

        if isPossible is True:
            for i in pos[1:]:
                print(i, end=' ')
            print()
        else:
            print(-1)
