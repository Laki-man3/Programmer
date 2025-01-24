for x in range(110203, 110245):
    a=[]
    if x%2 == 0:
        a = [x]
    for d in range(2,x//2+1):
        if x%d==0 and d%2==0:
            a.append(d)
    if len(a) == 4:
        a = sorted(a)
        print(a)
