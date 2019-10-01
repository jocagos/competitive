import sys, math


MAX_SIZE = 10 ** 6 + 7
ip = [True] * MAX_SIZE
primes = []

def sieve( upper_bound=(10**6 + 7) ):
    MAX_SIZE = upper_bound + 1
    ip = [True] * MAX_SIZE
    ip[0], ip[1] = False, False
    for i in range( 2, MAX_SIZE ):
        if ip[i]:
            for j in range( i * i, MAX_SIZE, i ):
                ip[j] = False
            primes.append(i)

    # end sieve

def is_prime( n ):
    if n < MAX_SIZE:
        return ip[n]
    for i in range( len( primes ) ):
        if n % primes[i] == 0:
            return False
    return True

n = int(sys.stdin.readline())
sieve()
print(is_prime(n))
