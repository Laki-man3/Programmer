a = "АОУ"
c = 0
for x1 in a:
    for x2 in a:
        for x3 in a:
            for x4 in a:
                for x5 in a:
                    s = x1+x2+x3+x4+x5
                    c += 1
                    if c == 210:
                        print(s)