def F(a,b):
    if a>b or a==15:
        return 0
    if a == b:
        return 1
    return F(a+1,b) + F(a*2,b) + F(a*3,b)
print(F(1,11)*F(11,25))