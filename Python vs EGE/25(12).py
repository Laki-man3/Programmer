c = 0
for x in range(2422000, 2422081):
    a = []
    for d in range(2,x//2+1):
        if x%d==0:
            a.append(d)
    if len(a) == 0:
        c+=1
        print(c,x)
