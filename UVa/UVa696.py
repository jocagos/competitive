import sys
import math

lines = sys.stdin.readlines()
for line in lines:
    s = line.split()
    m, n = int(s[0]), int(s[1])
    if m == 0 and n == 0:
        break
    if n > m:
        swap = True
        m, n = n, m
    else:
        swap = False
    if n == 1:
        ans = m
    elif n == 2:
        ans = m // 4 * 4 + (2 if m % 4 == 1 else ( 4 if m % 4 >= 2 else 0 ))
    else:
        ans = (n*m + 1)//2
    if swap:
        m, n = n, m
    print(int(ans), "knights may be placed on a", m, "row", n, "column board.")
