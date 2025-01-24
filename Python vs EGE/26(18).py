f = open("D:/pythonProject/26(18).txt")
n,m = map(int, f.readline().split())
a = []
t = 0
for x in f:
    if 200 <= int(x) <= 210:
        t += int(x)
    else:
        a.append(int(x))
a.sort()

n = len(a)
i = 0
while t + a[i] <= m:
    t += a[i]
    mg = a[i]
    i += 1
c = i

for  i in range(c + 1,n):
    if t - mg + a[i] <= m:
        t = t - mg + a[i]
        mg = a[i]
    else:
        break
print(c,t)
