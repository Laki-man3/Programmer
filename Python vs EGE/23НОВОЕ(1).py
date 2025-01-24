def F(a,b):
    if a>b or str(a).count("5")>0:
        return 0
    if a==b:
        return 1
    return F(a+1,b) + F(a*2,b)
print(F(1,60))