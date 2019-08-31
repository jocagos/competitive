import sys, datetime


first = sys.stdin.readline()
if ' ' in first:
    first = first.split(':')[0:2] + first.split(':')[2].split()
    n = first.count('')
    for i in range(n):
        first.remove('')
else:
    first = first.split(':')
    print(first[0], first[1], first[2].strip(), sep=':', end='')
    print(' 0.00 km')
h, m, s, d = int(first[0]), int(first[1]), int(first[2]), 0
v = float(first[3]) if len(first) >= 4 else 0
totalD, totalH, totalM, totalS = d, h, m, s
lines = sys.stdin.readlines()
for line in lines:
    q = False
    if ' ' in line:
        first = line.split(':')[0:2] + line.split(':')[2].split()
        n = first.count('')
        for i in range(n):
            first.remove('')
    else:
        first = line.split(':')
        q = True
    if q:
        print(first[0],first[1],first[2].strip(), sep=':', end='')
        totalH, totalM, totalS = int(first[0]), int(first[1]), int(first[2])
        totalD = d + (totalH - h) * v + (totalM - m) / 60 * v + (totalS - s) / 3600 * v
        print(' %.2f km' % (totalD))
    else:
        totalH, totalM, totalS = int(first[0]), int(first[1]), int(first[2])
        totalD = d + (totalH - h) * v + (totalM - m) / 60 * v + (totalS - s) / 3600 * v
        d = totalD
        h, m, s, v = totalH, totalM, totalS, float(first[3])
