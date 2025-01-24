f = open("D:/pythonProject/26(ДЕМО).txt")
n = int(f.readline())
l = [int(x) for x in f]
l.sort(reverse = True)
s = [l[0]]
for i in range(1, len(l)):
    if min(s) - l[i] >= 3:
        s.append(l[i])
print(len(s), min(s))
