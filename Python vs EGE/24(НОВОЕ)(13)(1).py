f = open("D:/pythonProject/24(НОВОЕ)(13).txt")
l = f.read()
l = l.replace("E", " ")
x = [i for i in l.split()]
maxc = 0
for s in x:
    if s.count("A")>= 3:
        maxc = max(maxc, len(s))
print(maxc)







