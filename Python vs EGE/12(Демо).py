for n in range(1000):
    s = ">" + "0"*39 + "1"*n + "2"*39
    while ">1" in s or ">2" in s or ">0" in s:
        if ">1" in s:
            s = s.replace(">1", "22>", 1)
        if ">2" in s:
            s = s.replace(">2", "2>", 1)
        if ">0" in s:
            s = s.replace(">0", "1>", 1)
    a = 0
    s = s.replace(">", "")
    for x in s:
        a += int(x)
    l = []
    for d in range(2, a//2+1):
        if a%d == 0:
            l.append(d)
    if len(l) == 0:
        print(n)
        break


