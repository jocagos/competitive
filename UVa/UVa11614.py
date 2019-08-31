import sys, math


def f(k):
    return int( (-1 + math.sqrt(1 + 8 * k) ) / 2 )

t = int(sys.stdin.readline())
lines = sys.stdin.readlines()
for line in lines:
    print(f(int(line)))
    
