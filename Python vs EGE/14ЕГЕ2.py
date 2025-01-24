def F(r):
    a = [0] * 7
    for i in range(7):
        a[i] = r.count(str(i))
    m=0
    k=0
    for x in range(7):
        if a[x]>m:
            m = a[x]
            k = x
    return k
n = 3*343**8+5*49**12+7**15-49
r = ''
while n>0:
    r = str(n % 7) + r
    n = n//7
print(F(r))

