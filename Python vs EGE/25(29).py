c = 0
x = 200000000
while c < 5:
    x +=1
    a = [x]
    for d in range(2,int(x**0.5)+1):
        if x%d == 0:
            a.append(d)
            if d*d!=x:
                a.append(x//d)
    if len(a)>=5:
        a = sorted(a)
        M = a[0]*a[1]*a[2]*a[3]*a[4]
        if M<x:
            c += 1
            print(M)
