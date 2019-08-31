import sys

def gcd( a, b ):
    if a < b:
        return gcd( b, a )
    while b != 0:
        b, a = a % b, b
    return a

t = int(sys.stdin.readline())
for i in range(t):
    line = sys.stdin.readline().strip().split()
    a, b = int(line[0]), int(line[2])
    g = gcd( a, b )
    a, b = a // g, b // g
    print(a, '/', b)

