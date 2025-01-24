for x in range(185311, 185330):
    a=[1,x]
    for d in range(2,x//2+1):
        if x%d==0:
            a.append(d)
    if len(a) == 4:
        a = sorted(a)
        print(a)
