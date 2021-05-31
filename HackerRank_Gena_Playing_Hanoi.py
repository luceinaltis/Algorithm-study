def Hanoi(posts, pos):
    if pos == -1:
        return 0

    if posts[pos] != 1:
        return 1 + 2 * Hanoi(posts, pos-1)
    else:
        return 0 + 2 * Hanoi(posts, pos-1)


def main():
    n = int(input())
    posts = list(map(int, input().split()))

    print(Hanoi(posts, len(posts) - 1))
    print(Hanoi(posts, len(posts) - 1))

    return 0


main()
