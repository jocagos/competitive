import sys


n, x, y = map(int, sys.stdin.readline().split())
a = sys.stdin.readline()
ans = 0
for i in range(n - x, n):
    if i == n - y - 1:
        ans = ans + 1 if a[i] == '0' else ans
    elif a[i] != '0':
        ans += 1

print(ans)
