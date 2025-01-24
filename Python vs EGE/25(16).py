for x in range(123456789, 223456789+1):
    if int(x**0.5)**2 == x:
        a = set()
        for d in range(2, int(x**0.5)+1):
            if x%d == 0:
                a.add(d)
                a.add(x//d)
                if len(a)>3:
                    break
        if len(a) == 3:
            print(x, max(a))