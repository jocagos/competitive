import sys
import math

t = int(sys.stdin.readline())

for i in range(t):
    s = sys.stdin.readline().split(' ')
    d, x, y = int(s[0]), int(s[1]), int(s[2])
    if x == 0 and y == 0:
        print(0)
        continue
    euc_dist = math.sqrt(x ** 2 + y ** 2)
    d = math.sqrt(d)
    if euc_dist > d:
        print(int(math.ceil(euc_dist / d )))
    else:
        print(int(math.ceil(d / euc_dist) ) )
