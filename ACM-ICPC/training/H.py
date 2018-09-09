import sys, math

t = int(sys.stdin.readline())
c2 = math.log10( 2 )
c5 = math.log10( 5 )
while t:
    line = sys.stdin.readline().split()
    a, b = int(line[0]), int(line[1])
    ans = int( math.ceil( a * c2 + b * c5 ) )
    if a == b: ans = ans + 1
    print(ans)
    t -= 1
