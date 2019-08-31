import sys


n = int(sys.stdin.readline())
v = sorted(list(map(int, sys.stdin.readline().split())))
c = [0]*n
for i in v:
    c[i] += 1
ans = 0
for key in range(n):
    if c[key
