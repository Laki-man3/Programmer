a = "01234567"
c = 0
for x1 in a:
    for x2 in a:
        for x3 in a:
            for x4 in a:
                for x5 in a:
                    s = x1+x2+x3+x4+x5
                    if s[0] != "0" and s.count("6") == 1 and s.count("16") == 0 and s.count("61") == 0 and s.count("36") == 0 and s.count("63") == 0 and s.count("56") == 0  and s.count("65") == 0 and s.count("76") == 0 and s.count("67") == 0:
                        c += 1
print(c)