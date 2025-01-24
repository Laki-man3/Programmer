for x in range(174457, 174506):
    a=[]
    for d in range(2,x//2+1):
        if x%d==0:
            a.append(d)
    if len(a) == 2:
        print(a)

