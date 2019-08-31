import sys, math


t = int(sys.stdin.readline())
for c in range(1, t + 1):
    n, l = map( int, sys.stdin.readline().split() )
    vals = list( map( int, sys.stdin.readline().split() ) )
    p = [0] * (len(vals) - 1)
    for idx in range(len(vals) - 1):
        p[idx] = math.gcd( vals[idx], vals[idx + 1] )
    primes = []
    for idx in range(len(p) - 1):
        primes.append( vals[idx] // p[idx] )
    print('primes are:', sorted( primes ) )
    le_primes = dict( zip( p, list( range( len( vals ) ) ) ) )
    print('Case #', c, ": \n", p, sep='')
