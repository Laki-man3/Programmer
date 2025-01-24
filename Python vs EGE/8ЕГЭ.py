a = "КАТЕР"
c = 0
for x1 in a:
    for x2 in a:
        for x3 in a:
            for x4 in a:
                for x5 in a:
                    for x6 in a:
                        s = x1+x2+x3+x4+x5+x6
                        if s[0] == "Р" and s[-1] == "К":
                            c += 1
print(c)