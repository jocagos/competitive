import sys, math
    

max_n = 1000001
sieve = [True] * max_n
sieve[0] = False
sieve[1] = False
primes = [0] * 78495
idx = 0
def is_prime( n ):
    if n < max_n:
        return sieve[n]
    else:
        ans = True
        for p in primes:
            if p * p > n:
                break
            if n % p == 0:
                ans = False
                break
        return ans
            
for i in range(2, max_n):
    if sieve[i]:
        j = 2
        if idx < len(primes):
            primes[idx] = i
        else:
            primes.append(i)
        idx += 1
        while j * i < max_n:
            sieve[j * i] = False
            j += 1

n = int(sys.stdin.readline())
ans = 1
for p in primes:
    if p * p * p > n: break
    cnt = 1
    while n % p == 0:
        n //= p
        ++ cnt
    ans *= cnt

r = int(math.sqrt(n))
if is_prime(n):
    ans *= 2
elif r * r == n and sieve[r]:
    ans *= 3
elif n != 1:
    ans *= 4
print(ans)
