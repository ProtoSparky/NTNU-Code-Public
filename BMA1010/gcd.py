def gcd(x, y):
    a = x
    b = y
    while b != 0:
        r = a % b
        a = b
        b = r
    return a

print(gcd(28314, 28317))
