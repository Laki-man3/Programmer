def fmbc(n, a):
    res = []
    for ai in a:
        mcost = -1
        for i in range(101):
            for j in range(i + 1, 101):
                for k in range(j + 1, 101):
                    cost = 2**i + 2**j + 2**k
                    if cost <= ai:
                        mcost = max(mcost, cost)
        res.append(mcost)
    return res

n = int(input())
a = [int(input()) for _ in range(n)]

res = fmbc(n, a)

for result in res:
    print(result)
