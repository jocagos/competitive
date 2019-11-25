import sys, math


tc = int(sys.stdin.readline())
while tc:
    l = list(map(int, sys.stdin.readline().split()))
    m = -1
    for i in range(len(l)):
        for j in range(len(l)):
            if i != j:
                m = max( m, math.gcd( l[i], l[j] ) )
    print(m)
    tc -= 1
