for n in range(1000):
    s = 39 * 3 + n * 4
    #Проверяем является ли s простым
    flag = True # гипотеза, что s - простое
    for d in range(2, s//2+1):
        if s % d == 0: #d - делитель s
            flag = False
            break
    if flag == True:  #число s - простое
        print(n, s)
        break



