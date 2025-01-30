def min_corr(n, m, a):
    dayone = a[0]
    daytwo = a[1]
    dayother = sorted(a[2:])
    daysgood = 0
    
    for day in dayother:
        if dayone <= day <= daytwo:
            daysgood += 1
            
    if daysgood >= m:
        return 0

    corr = 0
    ind = 0
    
    while daysgood < m and ind < len(dayother) and dayother[ind] < dayone:
        corr += dayone - dayother[ind]
        daysgood += 1
        ind += 1
        
    ind = len(dayother) - 1
    while daysgood < m and ind >= 0 and dayother[ind] > daytwo:
        corr += dayother[ind] - daytwo
        daysgood += 1
        ind -= 1

    return corr

n, m = map(int, input().split())
a = list(map(int, input().split()))

result = min_corr(n, m, a)
print(result)
