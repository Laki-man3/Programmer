f = open("D:/pythonProject/24(30).txt")
l = f.readline()
c = 0
k = 0
m = 0
for i in range(len(l)-1):
    if l[i] == "A":
        k = c
        c = 0
        m = max(m, c + k + 1)
    else:
        c +=1
    m = max(m, c + k + 1)
print(m)
