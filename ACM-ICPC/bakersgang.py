import sys


t = int(sys.stdin.readline())
for i in range(t):
    n = int(sys.stdin.readline())
    ans = (n ** (n+1) - n + 1) % 1000000007
    print(ans)
    
