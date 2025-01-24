def F(a,b):
    if a<b:
        return 0
    if a==b:
        return 1
    return F(a-2,b) + F(a-5,b)
print(F(22,2))