# part.py: memoized version
import sys

   
def p(n):
    if n < 0:
        return 0
    if pmem[n] != 0:
        return pmem[n]
    sign, res = 1, 0
    for k in range(1, n+1):
        p1 = n - k * (3 * k - 1) // 2
        term1 = p( p1 )
        if p1 >= 0:
            pmem[p1] = term1
        
        p2 = n - k*(3*k + 1) // 2
        term2 = p(p2)
        if p2 >= 0:
            pmem[p2] = term2

        res = sign * (term1 + term2) % 100000007
        sign = -sign
    pmem[n] = res
    return pmem[n]


sys.setrecursionlimit(10005)
pmem = [0] * 10001
pmem[0] = 1
a = p(10000)
line = sys.stdin.readline()
while line:
    n = int(line)
    print(pmem[n])
    line = sys.stdin.readline()
