f = open("D:/pythonProject/24(НОВОЕ)(7).txt")
l = f.read()
c = 0
m = 0
g = "AO"
s = "CDF"
for i in range(len(l) - 2):
    if (l[i] in g and l[i+1] in g and l[i+2] in g) or (l[i+2] in g and l[i] in g and l[i+1] in g) or (l[i+1] in g and l[i+2] in g and l[i] in g):
        c += 1
    else:
        m = max(m, c)
        c = 1
print(m//2)
