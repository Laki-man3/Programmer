f = open("D:/pythonProject/scr.txt")
l = f.read()
m = 0
t = 1
s = 'CDF'
g = "AO"
for i in range(len(l)-1):
    if (l[i] in s and l[i+1] in g) or (l[i+1] in s and l[i] in g):
        t += 1
    else:
        m = max(m, t)
        t = 1
print(m//2)