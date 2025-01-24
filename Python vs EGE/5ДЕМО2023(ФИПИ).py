for n in range(1,1000):
    d = bin(n)[2:]
    if n%3 == 0:
        r = d + d[-3:]
    else:
        r = d + bin((n%3)*3)[2:]
    r = int(r,2)
    if r >= 76:
        print(n)
        break