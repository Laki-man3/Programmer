for n in range(2,1000):
    x = n
    r = ""
    while n>0:
        r = str(n%2) + r
        n = n//2
    k1 = k0 = 0
    for i in range(len(r)):
        if i%2 == 1 and r[i] =='1':
            k1 = k1 + 1
        if i%2 == 0 and r[i] =='0':
            k0 = k0 + 1
    if abs(k1-k0) == 4:
        print(x)
        
