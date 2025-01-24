a = "ABCDEXZ"
c = 0
for x1 in "XZ":
    for x2 in "XZ":
        for x3 in "ABCDE":
            for x4 in "ABCDE":
                s = x1+x2+x3+x4
                c += 1
print(c)
