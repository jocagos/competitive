import sys, math


def bin_exp( a, b, m=1 ):
    a %= m
    res = 1
    while b > 0:
        if b % 2:
            res = res * a % m
        a = a * a % m
        b = b >> 1
    return res

def bin_sum( a, b, m=1 ):
    if b == 0:
        return 1
    elif b % 2:
        return (1 + a) * bin_sum( a * a, (b - 1)/2, m ) % m
    else:
        return 1 + (a + a * a) * bin_sum( a * a, (b - 2) / 2, m ) % m


def geometric(n,b,m):
    T=1
    e=b%m
    total = 0
    while n>0:
        if n&1==1:
            total = (e*total + T)%m
        T = ((e+1)*T)%m
        e = (e*e)%m
        n = n/2
        # print '{} {} {}'.format(total,T,e)
    return total


t = int(sys.stdin.readline())
MOD = 10 ** 9 + 7
for _ in range(t):
    m, n, p, q = map(int, sys.stdin.readline().split())
    # p_q = int(bin_exp( p, q, MOD ))
    # print 'p ** q + 1 % MOD =' + str((p_q * p - 1)//(p - 1) % MOD)
    # s = (p_q * p % MOD - 1) // (p - 1) % MOD
    # s *= 2 * (m + n) % MOD
    # s = s % MOD
    s = bin_sum( p, q, MOD )
    t = geometric( p, q, m )
    print str(s) + ' vs ' + str(t)
    
