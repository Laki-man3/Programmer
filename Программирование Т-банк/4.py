def opsmin(n, x, y, z, a):
    def opsmindiv(d):
        min_ops = float('inf')
        for num in a:
            if num % d == 0:
                return 0
            min_ops = min(min_ops, (d - num % d) % d)
        return min_ops

    ops_x = opsmindiv(x)
    ops_y = opsmindiv(y)
    ops_z = opsmindiv(z)

    ops_xy = opsmindiv(x * y // math.gcd(x, y))
    ops_xz = opsmindiv(x * z // math.gcd(x, z))
    ops_yz = opsmindiv(y * z // math.gcd(y, z))

    ops_xyz = opsmindiv(x * y * z // math.gcd(math.gcd(x, y), z))

    return min(ops_x + ops_y + ops_z, ops_xy + ops_z, ops_xz + ops_y, ops_yz + ops_x, ops_xyz)

import math

n, x, y, z = map(int, input().split())
a = list(map(int, input().split()))

res = opsmin(n, x, y, z, a)

print(res)
