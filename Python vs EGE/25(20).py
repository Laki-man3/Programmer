for x in range(101000000,102000001): #x = 2p**2
    if x%2 == 0:
        y = x//2
        if int(y**0.5)**2 == y: # y = квадрат какого либо числа
            #проверяем на простоту число p = y**0,5
            p = y**0.5
            flag = True
            for d in range(2,int(p**0.5)+1):
                if p%d == 0:
                    flag = False
                    break
            if flag == True:
                print(x)
