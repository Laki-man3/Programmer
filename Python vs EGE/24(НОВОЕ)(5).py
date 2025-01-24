f = open("D:/pythonProject/24(НОВОЕ)(5).txt")
l = f.readline()
c = m = 0
for i in range(len(l)-1):
    if (l[i] not in "ABC") or (l[i+1] not in "ABC"):
        c += 1
        m = max(m, c)
    else:
        c = 1
print(m)
