import sys


cin = sys.stdin
der = [-1] * 1000000
fac = [-1] * 1000000
P = [-1.0] * 1000000
der[0], der[1] = 1, 0
fac[0], fac[1] = 1, 1
def d( n ):
    if n == 0: return der[0]
    if n == 1: return der[1]
    if n > 1 and der[n] != -1: return der[n]
    der[n] = (n - 1) * (d( n - 1 ) + d( n - 2 ))
    return der[n]

def f( n ):
    if n == 0 or n == 1 or (n > 1 and fac[n] != -1):
        return fac[n]
    fac[n] = n * f( n - 1 )
    return fac[n]

a = d( 101 )
eps = 0.0000001
ans = 0
for i in range( 101 ):
    a = der[i]
    # print('Derangement for', i, 'is', a)
    if a != 0:
        # print('Probability for', i, 'is:', 1 - a / f(i) )
        P[i] = 1 - a / f(i)
    if i > 2:
        dd = abs(P[i] - P[i - 1])
        if dd < eps:
            ans = i
            break
        # print('Diff:', dd)

# print('ans is', ans)
for i in range( ans + 1 ):
    print('{', i, ',', P[i], '}')

