f = open("D:/pythonProject/24(2).txt")
s = f.read()
m = 0
k = 0
for x in s:
    if x == "X":
        k+=1
    else:
        m = max(m,k)
        k = 0
print(m)