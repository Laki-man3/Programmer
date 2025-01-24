f = open("D:/pythonProject/24(1).txt")
s = f.read()
m = 0 # максимальное
k = 1 # текущее
for i in range(len(s)-1):
    if s[i]!=s[i+1]:
        k+=1
    else:
        m = max(m,k)
        k = 1
print(m)