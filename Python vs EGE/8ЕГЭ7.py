k=0
a='ЕГЭ'
for x1 in a:
    for x2 in a:
        for x3 in a:
            for x4 in a:
                for x5 in a:
                    s=x1+x2+x3+x4+x5
                    if s[0]=='Е' or s[0]=='Э':
                        k+=1
print(k)

