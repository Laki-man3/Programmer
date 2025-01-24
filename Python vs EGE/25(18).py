for x in range(1000000, 2000001):
    a = set()
    for d in range(2, int(x**0.5)+1):
        if x%d==0 and abs((x//d) - d) <= 100:
            a.add(abs((x//d) - d))
        if len(a) >= 3:
            print(x)
            break
