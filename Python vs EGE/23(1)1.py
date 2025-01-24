def F(a,b):
    if a>b:
        return 0
    if a==b:
        return 1
    return F(a+1,b) + F(a+2,b) + F(a*2,b)
print(F(3,10)*F(10,12))