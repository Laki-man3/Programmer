def F(a,b):
    if a>b:
        return 0
    if a==b:
        return 1
    return F(a+1,b) + F(a+10,b)
print(F(35,57))