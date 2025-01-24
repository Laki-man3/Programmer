for s in range(101,110):
    i = "1"*s
    while "111" in i:
        i = i.replace("111","22",1)
        i = i.replace("222","11",1)
    print(i,s)
print("Ответ 103")
