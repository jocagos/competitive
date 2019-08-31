import sys


n = int(sys.stdin.readline().strip()) + 1
if n - 1 == 0:
    print(0)
elif n % 2 == 0:
    print(n//2)
else:
    print(n)
