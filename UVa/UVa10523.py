import sys


def f( n, a ):
    # po, su = [a]*n, [a]*n
    # for i in range(1, n):
    #     po[i] = po[i - 1] * a
    #     su[i] = su[i - 1] + po[i]
    # maybe = su[-1]
    # for i in range(1, n):
    #     maybe += su[-1] - su[i - 1]
    # Somehow this is faster
    r, ans = a, 0
    for i in range(1, n + 1):
        ans += r * i
        r *= a
    return ans # return maybe

line = sys.stdin.readline()
while line:
    n, a = map(int, line.split())
    print(f(n, a ))
    line = sys.stdin.readline()
