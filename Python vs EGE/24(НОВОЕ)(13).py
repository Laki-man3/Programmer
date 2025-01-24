f = open("D:/pythonProject/24(НОВОЕ)(13).txt")
l = f.readline()
c = m = 0
for i in range(len(l)):
    if l[i] == "E" and l[i + 1] != "A":
        c = 0
    else:
        c += 1
        m = max(m, c)
print(m)


