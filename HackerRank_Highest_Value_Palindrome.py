import subprocess


def getPalindrome(n, k, numStr):
    mid = n // 2
    changed = [0] * n
    nums = list(map(int, list(numStr)))
    for i in range(mid+1):
        l = i
        r = n - 1 - i

        if nums[l] == nums[r]:
            continue
        elif nums[l] > nums[r]:
            changed[r] = 1
            k -= 1
            nums[r] = nums[l]
        elif nums[l] < nums[r]:
            changed[l] = 1
            nums[l] = nums[r]
            k -= 1
    if k < 0:
        return '-1'

    for i in range(mid+1):
        l = i
        r = n - 1 - i

        if nums[l] == 9 and nums[r] == 9:
            continue
        if k >= 1 and l == r:
            changed[l] = 1

            nums[l] = 9
            k -= 1

        if k >= 2 and changed[l] == 0 and changed[r] == 0:
            changed[l] = 1
            changed[r] = 1

            nums[l] = 9
            nums[r] = 9
            k -= 2
        elif k >= 1 and (changed[l] == 1 or changed[r] == 1):
            changed[l] = 1
            changed[r] = 1

            nums[l] = 9
            nums[r] = 9
            k -= 1

    return ''.join(list(map(str, nums)))


if __name__ == '__main__':
    n, k = list(map(int, input().split()))
    numStr = input()
    highestPalindrome = getPalindrome(n, k, numStr)
    print(highestPalindrome)
