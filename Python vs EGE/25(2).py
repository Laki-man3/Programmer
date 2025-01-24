for x in range(245690, 245756):
    a=[]
    for d in range(2,x//2+1):
        if x%d==0:
            a.append(d)
    if len(a) == 0:
        print(x-245690+1,x)
