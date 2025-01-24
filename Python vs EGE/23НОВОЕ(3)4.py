def F(a,b,Flag):
    if a>b:
        return 0
    if a == b:
        return 1
    if Flag:
        return F(a+1,b,True) + F(a+2,b,True) + F(a*2,b,False)
    return F(a+1,b,True) + F(a+2,b,True)
print(F(1,9,True))