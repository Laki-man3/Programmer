c = 0
x = 452021
while c < 5:
    x +=1
    a = []
    for d in range(2,x//2 + 1):
        if x%d == 0:
            a.append(d)
    if len(a)>0:
        M = max(a) + min(a)
        if M%7 == 3:
            c += 1
            print(x, M)
