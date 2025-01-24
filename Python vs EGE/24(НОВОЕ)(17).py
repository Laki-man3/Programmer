f = open("24(НОВОЕ)(17).txt")
l = f.readline()
m = c = 0
for i in range(len(l) - 1):
    if l[i] == "P" and l[i+1] == "P":
        c = 1
    else:
        c += 1
        m = max(m, c)
print(m)
