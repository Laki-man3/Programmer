f = open("24(НОВОЕ)(18).txt")
l = f.readline()
m = c = 0
for i in range(len(l)):
    if l[i-1:i+1] not in ['da', 'ad']:
        c += 1
        m = max(m, c)
    else:
        c = 1
print(m)
