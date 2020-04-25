import sys, math


n = int(sys.stdin.readline())
if n < 10:
    print(n)
else:
    digits = int(math.floor( math.log10( n ) + 1 ))
    p = 10 ** (digits - 1)
    lead = n // p
    m = n % p
    m -= p // 2
    if m >= 0:
        print((lead + 1) * p)
    else:
        print(lead * p)
