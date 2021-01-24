import sys


getline = sys.stdin.readline
tc = int(getline())
while tc > 0:
    line = getline()
    keys = list(map(int, getline().split(' ')))
    vals = list(getline().strip().split(' '))
    L = sorted([(k, v) for k, v in zip(keys, vals)])
    for i, (k, v) in enumerate(L):
        print(v)
    tc -= 1
    if tc > 0:
        print()
    
    
