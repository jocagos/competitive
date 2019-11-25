import sys
from timeit import default_timer as timer


MOD = 1000 ** 3 + 7

def inv( a, m=MOD ):
    return pow(a, m - 2, m)

def f( a, b, x ):
    a %= MOD
    b %= MOD
    x %= MOD
    return ((a * x)%MOD + b % MOD) % MOD

def g( a, b, n, x ):
    if n == 1:
        return f(a, b, x) % MOD
    m = lambda val, mod : val % mod
    a, b, n, x = map( m, [a, b, n, x], [MOD]*4 )
    res = 0
    # A^n % MOD
    res += pow(a, n, MOD) * x % MOD
    # geometric series % MOD
    res += (pow(a, n, MOD) - 1) * inv(a - 1) % MOD * b % MOD
    return res

a, b, n, x = map(int, sys.stdin.readline().split())
print(g(a, b, n, x))
