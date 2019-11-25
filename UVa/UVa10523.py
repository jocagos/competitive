import sys


def f( n, a ):
    r, ans = a, 0
    for i in range(1, n + 1):
        ans += r * i
        r *= a
    return ans

line = sys.stdin.readline()
while line:
    n, a = map(int, line.split())
    print(f(n, a))
    line = sys.stdin.readline()
