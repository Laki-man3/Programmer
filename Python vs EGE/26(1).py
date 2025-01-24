f = open("D:/pythonProject/26_demo.txt")
s, n = map(int, f.readline().split())
a = [int(x) for x in f]
a = sorted(a)
t = 0 #текущая сумма файлов
i = 0 #пользователь
while t + a[i] <= s:
    t = t + a[i]
    m = a[i] #макс размер файла
    i +=1
c = i # количество пользователей

for i in range(c+1,n):
    if t - m + a[i] <= s:
        t = t-m + a[i]
        m = a[i]
    else:
        break
print(c, m)
