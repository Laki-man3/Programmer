f = open("D:/pythonProject/24(22).txt")
d = ""
mm = 10**6
for s in f:
    if s.count("G") < mm: #Строка находится в файле раньше(строго меньше(<))
        mm = s.count("G")
        a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        m = 0
        for c in a:
            if s.count(c)>=m: #буква стоит позже в алфавите(не строгое неравенство(>=))
                m = s.count(c)
                d = c
print(d)

