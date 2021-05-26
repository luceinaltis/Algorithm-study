def balanced(l, dic):
    ans = True
    for i in dic:
        if dic[i] > l:
            ans = False
            break
    return ans


def steadyGene(gene):
    dic = {'C': 0, 'G': 0, 'A': 0, 'T': 0}

    l = len(gene)//4
    for ch in gene:
        dic[ch] += 1

    left = 0
    right = 0
    minLen = len(gene)
    while left < len(gene) and right < len(gene):
        if not balanced(l, dic):
            dic[gene[right]] -= 1
            right += 1
        else:
            minLen = min(minLen, right - left)
            dic[gene[left]] += 1
            left += 1

    return minLen


def main():
    n = input()
    gene = input()

    ans = steadyGene(gene)

    print(ans)
    return


main()
