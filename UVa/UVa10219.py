import sys

def fact( n ):
    if n == 0 or n == 1:
        return 1
    else:
        for i in range(2, n):
            n = n * i
        return n

def choose( n, k ):
    return fact(n) // ( fact(k) * fact(n-k) )

lines = sys.stdin.readlines()
for line in lines:
    if line == '\n':
        break
    s = line.split(' ')
    n, k = int(s[0]), int(s[1])
    d = str(choose(n, k))
    print(len(d))
