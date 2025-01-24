def perevod(n,m):
    r = ''
    while n>0:
        s = str(n%m) + r
        n = n//m
    return int(r)

for n in range(2, 50):
    r = str(perevod(n,2))
    if r.count('1') % 2 == 0:
        r = '10' + r[2:] + '0'
    else:
        r = '11' + r[2:] + '1'
    if int(r,2)>40:
        print(n)


