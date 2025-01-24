a = []
for m in range(0,100,2):
    for n in range(1,100,2):
        N = 2**m*3**n
        if 200000000 <= N <400000001:
            a.append(N)
print(sorted(a))





