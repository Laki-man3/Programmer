f = open("D:/pythonProject/24(5).txt")
s = f.read()
m = 0
k = 0
n = 0 #X(0) Y(1) Z(2)
for i in s:
    if i == "X" and n == 0 or i == "Y" and n == 1 or i == "Z" and n == 2:
        k+=1
        n = (n+1)%3
    else:
        m = max(m,k)
        if i == "X":
            k = 1
            n = 1
        else:
            k = 0
            n = 0
print(m)