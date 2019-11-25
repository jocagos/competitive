import sys


n = int(sys.stdin.readline())
while n:
    a, b = sys.stdin.readline().split()
    a, b = a[::-1], b[::-1]
    c = int(str(int(a) + int(b))[::-1])
    print(c)
    n -= 1
