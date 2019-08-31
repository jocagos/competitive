# Got AC 09/05/18 02:14, took 0.609375s for Igen.in
import sys, math # , time


# Combination of LLT, DP, Sieve, math
def binExp( b, e ): # Not used, sometimes required!
    if b == 0:
        return 0
    if b == 1 or e == 0:
        return 1
    if e == 1:
        return b
    if e % 2 == 1:
        return b * binExp( b * b, (e - 1) / 2 )
    else:
        return binExp( b * b, e / 2 )

def llt( p ): # Best primality test for Mersenne numbers, using a little DP too
    if bs[p]:
        # Try it
        if mprimes[p] == 1:
            return True
        elif mprimes[p] == 0:
            return False
        else:
            s = 4
            m = ( 1 << p ) - 1 # faster than binExp I think, took no time!
            for i in range( 3, p + 1 ):
                sqr = s * s
                s = ( sqr & m ) + ( sqr >> p ) # little trick here
                if s >= m:
                    s -= m
                s -= 2
            if s == 0:
                mprimes[p] = 1
                return True
            else:
                mprimes[p] = 0
                return False
    else:
        return False

# start = time.process_time()
idx = 0 # to keep appending to primes, optimizes appends
bs = [True] * 2001 # bitset
bs[0], bs[1] = False, False # initialize it
primes = [-1] * 2001 # primes as a vector of idx numbers
mprimes = [-1] * 2001 # mersenne prime exponents 
    
# Sieve of Erathostenes, good enough (atkin's harder in a contest!)
for i in range(2, 2001):
    if bs[i]: # if number is not marked
        for j in range( i * i, 2001, i ): # mark its multiples
            bs[j] = False # as False
            mprimes[j] = 0 # memoization too
        primes[idx] = i # add it to the primes list if required
        idx += 1 # up the bound
    else:
        mprimes[i] = 0 # memoization too

line = sys.stdin.readline() # keep reading lines
while line: # with this trick, faster than input()!
    line = line.split()
    p = int(line[0]) + int(line[1]) # we just need the sum
    if p == 2:
        print('2^2-1 is prime') # corner case for LLT
    else: # the fun begins here
        if llt( p ): # just test (first memo then manually)
            print('2^', p, '-1 is prime', sep='') # and print
        else:
            print('2^', p, '-1 not prime', sep='') # if yes or no
    
    line = sys.stdin.readline() # then keep reading until EOF!

# elapsed = time.process_time() - start
# print('Elapsed:', elapsed)
