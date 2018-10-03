import sys, math


def newton( y ):
    print(y)
    x0 = int(str(y)[0:(len(str(y))//2)]) if y > 99 else 50
    x1 = x0 - (x0 * x0 - y)/(2*x0)
    while abs(x0 - x1) > 0:
        x0 = x1
        x1 = x0 - (x0 * x0 - y)/(2*x0)
    return int(x0)

t = int(sys.stdin.readline())
for i in range(t):
    sys.stdin.readline()
    n = int(sys.stdin.readline())
    print(newton(n))
    print("---")
