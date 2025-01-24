def F(a,b):
    if a>b or a==26:
        return 0
    if a==b:
        return 1
    return F(a+1,b) + F(2*a+1,b)
print(F(1,27))