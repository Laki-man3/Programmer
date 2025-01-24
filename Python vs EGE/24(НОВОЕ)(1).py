f = open("D:/pythonProject/24(НОВОЕ)(1).txt")
l = f.readline()
c = m = 1
for i in range(len(l)-2):
    if (int(l[i]) + int(l[i+1]))>int(l[i+2]):
        c += 1
        m = max(m, c)
    else:
        c = 1
print(m)

