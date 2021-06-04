def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    sorted_numbers = [(num, idx) for idx, num in enumerate(numbers)]
    sorted_numbers.sort()

    minLoss = 10**16
    for i in range(1, n):
        loss = sorted_numbers[i][0] - sorted_numbers[i-1][0]
        if loss < minLoss and sorted_numbers[i-1][1] > sorted_numbers[i][1]:
            minLoss = loss
    print(minLoss)

    return 0


main()
