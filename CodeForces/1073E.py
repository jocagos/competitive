import math


f = [-1] * 1000001
f[0], f[1] = 1, 1
def fact( n ):
    if f[n] == -1:
        f[n] = n * fact( n - 1 )
    return f[n]


def nk( n, k ):
    return f[n] / ( f[n - k] * f[k] )


def st( m, n ):
    s = 0
    for i in range( 0, n +  1 ):
        s += ((-1) ** (n - i)) * nk( n, i ) * (i ** m)
    return s

for i in range(11):
    print('f[', i, '] = ', fact(i), sep='')
for i in range(11):
    print('nk(', i,', ', 0, ') = ', nk( i, 0 ), sep='')
print(st(2, 10))
