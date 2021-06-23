from collections import defaultdict

if __name__ == '__main__':
    n, m, k = list(map(int, input().split()))

    domain = defaultdict(lambda: [])
    for _ in range(k):
        r, c1, c2 = list(map(int, input().split()))

        union_set = [[c1, c2]]
        new_domain = []
        for idx, val in enumerate(domain[r]):
            if (val[0] <= c1 and c1 <= val[1]) or (val[0] <= c2 and c2 <= val[1]):
                union_set.append(val)
            else:
                new_domain.append(val)
        new_domain.append([min(union_set, key=lambda domain: domain[0])[0], max(
            union_set, key=lambda domain: domain[1])[1]])
        domain[r] = new_domain

    train = 0
    for key, val in domain.items():
        for f, t in val:
            train += (t - f + 1)
    print(n*m - train)
