import math


tc = int(input())
mod = 1000000007
for i in range(tc):
    n, t, m = map( int, input().split() )
    choose, fail, ext = map( math.factorial, [ n - m, t, n - m - t ] )
    probability = 1 - choose / (fail * choose)
    num, den = probability.as_integer_ratio()
    q = pow( den, mod - 2, mod ) # formula
    print(q)

