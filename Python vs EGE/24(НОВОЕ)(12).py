f = open("D:/pythonProject/24(НОВОЕ)(12).txt")
l = f.read()
c = m = 0
l = l.replace("AB", "x")
l = l.replace("CB", "x")
for i in range(len(l)):
    if l[i] == "x":
        c += 1
        m = max(m, c)
    else:
        c = 0
print(m)