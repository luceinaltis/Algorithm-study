if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        sum_arr = []
        sum = 0
        for i in arr:
            sum += i
            sum_arr.append(sum)

        isPossible = 'NO'
        for idx, val in enumerate(arr):
            if idx == 0:
                if sum_arr[len(arr) - 1] - arr[idx] == 0:
                    isPossible = 'YES'
                    break
            elif sum_arr[idx-1] == sum_arr[len(arr)-1] - sum_arr[idx]:
                isPossible = 'YES'
                break
        print(isPossible)
