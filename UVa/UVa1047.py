import sys, collections


n, r = -1, -1
zones = [-1]*22
while n != 0 and r != 0:
    intersects = {}
    n, r = map(int, sys.stdin.readline().split())
    zones = map(int, sys.stdin.readline().split())
    m = int(sys.stdin.readline())
    for i in range(m):
        vals = map(int, sys.stdin.readline().split())
        _, key, val = val[0], tuple(sorted(val[1:(1 + vals[0])])), vals[-1]
        intersects[key] = val
    mask = [1]*r + [0]*(n-r)
    
