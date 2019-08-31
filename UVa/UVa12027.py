import sys, math


for line in sys.stdin:
    n = int(line)
    if n == 0:
        break
    print(int(math.floor(math.sqrt(n))))
