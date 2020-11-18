import sys, fractions, math


line = sys.stdin.readline()
while line:
    n = int(line)
    l = int((-1 + math.sqrt( 1 + 8 * n ) ) // 2)
    r = l + 1
    steps = n - l
    b, a = max(l - steps, 1), 1 + steps
    print('n', n, 'l', l, 'r', r, 'steps', steps, 'b', b, 'a', a)
    ans = fractions.Fraction(a, b)
    print('THE', n, 'TERM IS', str(ans))
    line = sys.stdin.readline()
