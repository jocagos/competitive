import sys
import math

t = int(sys.stdin.readline())
for i in range(t):
    line = sys.stdin.readline()
    while line.isspace():
        line = sys.stdin.readline()
    s = line.split()
    piece, n, m = s[0], int(s[1]), int(s[2])
    if piece == 'Q': # n-Queens
        print(min(n, m))
    elif piece == 'r': # n-rooks
        print(min(n,m))
    elif piece == 'k': # n-knights
        if n % 2 == 1 and m % 2 == 1:
            print(int(math.ceil(n*m/2)))
        else:
            print(int(n*m/2))
    elif piece == 'K': # n-Kings
        print(int(math.ceil(n/2)*math.ceil(m/2)))
