import math, sys


n, p = 0, 0
line = sys.stdin.readline()
while line:
    n = int(line)
    line = sys.stdin.readline()
    p = int(line)
    print(int(p**( -n)))
    line = sys.stdin.readline()
