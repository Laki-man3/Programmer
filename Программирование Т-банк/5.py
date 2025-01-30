def calculate_f(n, s, a):
    
    prefix_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1]

    def f(l, r):
        total_length = prefix_sum[r] - prefix_sum[l - 1]
        if total_length <= s:
            return 1
        else:
            return (total_length + s - 1) // s

    total_sum = 0
    for l in range(1, n + 1):
        for r in range(l, n + 1):
            total_sum += f(l, r)

    return total_sum

n, s = map(int, input().split())
a = list(map(int, input().split()))

result = calculate_f(n, s, a)

print(result)
