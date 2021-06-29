

if __name__ == '__main__':
    n = int(input())
    st = input()
    k = int(input())
    if k > ord('z') - ord('a'):
        k %= (ord('z') - ord('a') + 1)

    rotatedSt = []

    for i in st:
        if 'a' <= i and i <= 'z':
            asc = ord(i) + k
            if asc > ord('z'):
                asc -= (ord('z') - ord('a') + 1)
            rotatedSt.append(chr(asc))
        elif 'A' <= i and i <= 'Z':
            asc = ord(i) + k
            if asc > ord('Z'):
                asc -= (ord('Z') - ord('A') + 1)
            rotatedSt.append(chr(asc))
        else:
            rotatedSt.append(i)

    print(''.join(rotatedSt))
