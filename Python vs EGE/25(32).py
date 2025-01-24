c = 0
x = 11000000
while c<5:
    x += 1
    a = []
    for d in range(2, int(x**0.5)+1):
        if x%d == 0:
            a.append(d)
            if d*d != x:
                a.append(x//d)
    if len(a)>=2:
        a.sort()
        M = a[-1] + a[-2]
        if M<10000:
            c +=1
            print(M)

