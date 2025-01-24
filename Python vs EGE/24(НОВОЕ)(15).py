f = open("D:/pythonProject/24(НОВОЕ)(15).txt")
l = f.read()
l = l.replace("DDDD", " ")
l = l.replace("DDD", " ")
l = l.replace("DD", " ")
x = [i for i in l.split()]
maxc = 0
for s in x:
    s = s.replace("D", " ")
    y = [i for i in s.split()]
    for i in range(len(y) - 1):
        maxc = max(maxc, len(y[i]) + len(y[i + 1]) + 1)
print(maxc)





