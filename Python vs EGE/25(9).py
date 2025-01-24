maxk = 0
for x in range(84052, 84130):
    a = [1,x]
    for d in range(2,x//2+1):
        if x%d==0:
            a.append(d)
    if len(a) > maxk: #найдите минимальное из них
        maxk = len(a)
        y = x
print(maxk, y)