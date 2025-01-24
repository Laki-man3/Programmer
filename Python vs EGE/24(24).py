f = open("D:/pythonProject/24(24).txt")
m = 0
for s in f:
    if s.count("A")<25:
        for i in range(len(s)-1):# символ с начала строки
            for j in range(len(s)-1,i,-1):# символ с конца строки
                if s[i] == s[j]:
                    m = max(m,j-i)
                    break
print(m)
