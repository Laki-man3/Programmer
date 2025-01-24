c = 0
x = 10000000
while c < 5:
    x +=1
    a = [1]
    for d in range(2,int(x**0.5)+1):
        if x%d == 0:
            a.append(d)
            if d*d!=x:
                a.append(x//d)
    if len(a)>=2:
        a = sorted(a)
        M = a[-1]+a[-2]
        if M<10000:
            c += 1
            print(M)
