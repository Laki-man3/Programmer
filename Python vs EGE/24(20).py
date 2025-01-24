f = open("D:/pythonProject/24(18).txt")
s = f.read()
r = ""
for i in range(len(s)-2):
    if s[i]==s[i+2]:
        r = r + s[i+1]
a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
m = 0
d = ""
for c in a:
    if r.count(c)>m:
        m = r.count(c)
        d = c
print(d)