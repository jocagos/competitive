import sys


n = int(sys.stdin.readline())
lines = []
for __ in range(n):
    f = int(sys.stdin.readline())
    ans = 0
    for __ in range(f):
        a, __, b = map(int, sys.stdin.readline().split())
        ans += a * b
    lines.append(str(ans) + '\n')

sys.stdout.writelines(lines)
