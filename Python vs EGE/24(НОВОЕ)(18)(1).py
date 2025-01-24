f = open("24(НОВОЕ)(18).txt")
l = f.read()
l = l.replace("ad", " ")
l = l.replace("da", " ")
x = [i for i in l.split()]
maxc = 0
for s in x:
    maxc = max(maxc, len(s) + 2)
print(maxc)


