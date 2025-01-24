f = open("D:/pythonProject/24(27).txt")
l = f.readline()
c = 1
m = 0
for i in range(1, len(l)):
    if (l[i]=="K" and l[i-1]=="L") or (l[i-1]=="K" and l[i]=="L"):
        c = 1
    else:
        c += 1
        if c>m:
            m = c
print(m)
