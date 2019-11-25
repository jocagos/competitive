import sys


ans = 0
n = int(sys.stdin.readline())
while n:
    ans += n
    n = int(sys.stdin.readline())
print(ans)
