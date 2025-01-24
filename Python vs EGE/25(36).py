a = []
for i in range(10):
    #для случая * - пустое место
    x = "1" + str(i) + "21394"
    x = int(x)
    if x % 2023 == 0:
        a.append(x)
    # * от 0 до 999

    for j in range(1000):
        x = "1" + str(i) + "2139" + str(j) + "4"
        x = int(x)
        if x % 2023 == 0:
            a.append(x)
a = sorted(a)
for x in a:
    print(x, x//2023)
