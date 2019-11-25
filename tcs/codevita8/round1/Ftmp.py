import sys


def kbonacci(k, n, m, b):
    c = b
    while n:
        i,*c = *c,k
        n -= 1
        k += k - i
    return str(c[0] % m)

T = int(sys.stdin.readline())
for _ in range(T):
    n, k = map(int,sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    print(kbonacci(k, n, 17, a))

