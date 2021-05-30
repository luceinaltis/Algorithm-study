def union(parent, rank, u, v):
    u = find(parent, u)
    v = find(parent, v)

    if u == v:
        return -1

    if rank[u] < rank[v]:
        u, v = v, u

    parent[v] = u

    if rank[u] == rank[v]:
        rank[u] += 1

    return 0


def find(parent, x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent, parent[x])
        return parent[x]

# return total weight


def kurskal(sorted_edges, g_nodes, g_edges):
    parent = [i for i in range(g_nodes+1)]
    rank = [1 for i in range(g_nodes+1)]

    totalWeight = 0
    for i in sorted_edges:
        if union(parent, rank, i['g_from'], i['g_to']) != -1:
            totalWeight += i['g_weight']
    return totalWeight


def main():
    g_nodes, g_edges = list(map(int, input().split()))
    edges = list()

    for i in range(g_edges):
        g_from, g_to, g_weight = list(map(int, input().split()))
        edges.append({'g_from': g_from, 'g_to': g_to, 'g_weight': g_weight})

    sorted_edges = sorted(edges, key=lambda k: k['g_weight'])

    print(kurskal(sorted_edges, g_nodes, g_edges))

    return 0


main()
