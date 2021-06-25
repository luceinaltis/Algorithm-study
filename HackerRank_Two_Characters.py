if __name__ == '__main__':
    s = int(input())
    string = input()

    asci = 'abcdefghijklmnopqrstuvwxyz'

    ans = 0
    for i in asci:
        for j in asci:
            if i == j:
                continue

            newString = []
            for c in string:
                if c == i or c == j:
                    if len(newString) == 0 or newString[-1] != c:
                        newString.append(c)
                    else:
                        newString = list()
                        break
            if len(newString) == 1:
                newString = []
            ans = max(len(newString), ans)

    print(ans)
