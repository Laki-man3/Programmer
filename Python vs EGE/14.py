a = "0123456789A"
for x in a:
    b = int("982"+x+"8",11) + int("194"+x+"7", 11)
    if b%58 == 0:
        print(b//58)


