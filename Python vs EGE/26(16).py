f = open("D:/pythonProject/26(16).txt")
n = int(f.readline())
a = []
s = 0
for x in f:
    if int(x) <= 50:
        s += int(x)
    else:
        a.append(int(x))
a.sort()

n = len(a)
for i in range(n//2):
    s = s + a[i]*0.75 + a[n-i-1]
    m = a[i]
if int(s) == s:
    print(int(s), m)
else:
    print(int(s) + 1, m)
