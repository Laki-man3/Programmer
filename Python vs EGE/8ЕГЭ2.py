a = "ПАРАБОЛА"
b = "АО"
c = "ПРБЛ"
d = []

k = 0
for x1 in a:
    for x2 in a:
        for x3 in a:
            for x4 in a:
                for x5 in a:
                    for x6 in a:
                        for x7 in a:
                            for x8 in a:
                                s = x1+x2+x3+x4+x5+x6+x7+x8
                                if s.count("П") == 1 and s.count("А") == 3 and s.count("Р") == 1 and s.count("Б") == 1 and s.count("О") == 1 and s.count("Л") == 1:
                                    if (s[0] in b and s[1] in c and s[2] in b and s[3] in c and s[4] in b and s[5] in c and s[6] in b and s[7] in c) or (s[0] in c and s[1] in b and s[2] in c and s[3] in b and s[4] in c and s[5] in b and s[6] in c and s[7] in b):
                                        if s not in d:
                                            d.append(s)
print(len(d))