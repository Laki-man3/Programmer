c = 0
x = 600000
while c < 5:
    x +=1
    a = []
    for d in range(17,x//2 + 1,10):
        if x%d == 0:
            a.append(d)
    if len(a)>0:
            c += 1
            print(x, min(a))
