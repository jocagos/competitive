import sys


n = int(sys.stdin.readline())
while n:
    if n % 17 == 0:
        print(1)
    else:
        print(0)
    n = int(sys.stdin.readline())
