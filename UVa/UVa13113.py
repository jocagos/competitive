import sys, math


tc = int(sys.stdin.readline())
MAXA, MAXB = 505, 1010
percs = [ [0 for i in range(MAXA)] for j in range(MAXB) ]
total_voters = [0 for i in range(MAXB)]
totals = [0.0 for i in range(MAXA)]
for c in range(tc):
    A, B = map( int, sys.stdin.readline().split() )
    for i in range(B):
        line = sys.stdin.readline().split()
        total_voters[i] = int(line.pop())
        percs[i] = list(map( float, line ))
    for i in range(A):
        totals[i] = math.fsum([percs[j][i] * total_voters[j] / 100.0 for j in range(B)])
    vals = sorted(list(zip(totals, range(1, A + 1))), key=lambda tup: (tup[0], -tup[1]))
    tot = 0
    for i in range(B):
        tot += total_voters[i]
    rounds = 2
    if vals[-1][0] >= tot * 0.501:
        rounds = 1
    for i in range(1, rounds + 1):
        print(vals[-i][1], int(vals[-i][0]))
    if c + 1 < tc:
        print()
