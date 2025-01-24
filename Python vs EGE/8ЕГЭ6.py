k = 0
a = "12345"
for x in a:
    for y in a:
        for z in a:
            for w in a:
                for n in a:
                    s = x+y+z+w+n
                    if s.count("1") == 3:
                        k +=1
print(k)

