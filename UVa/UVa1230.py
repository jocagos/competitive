import sys, math


c = int(sys.stdin.readline())
for i in range(c):
    line = sys.stdin.readline().split()
    x, y, n = int(line[0]), int(line[1]), int(line[2])
    print(pow(x, y, n))
