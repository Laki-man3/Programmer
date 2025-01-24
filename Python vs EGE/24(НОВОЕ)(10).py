f = open("D:/pythonProject/24(НОВОЕ)(10).txt")
l = f.read()
l = l.replace("A", " ")
x = [i for i in l.split()]
c = 0
for s in x:
    if len(s)>= 8 and s.count("B") == 0:
        c += 1
print(c)



