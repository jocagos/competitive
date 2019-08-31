import sys


n = int(sys.stdin.readline() )
for i in range(n):
    s = sys.stdin.readline()
    last = int(s[-1])
    s = s[:-1]
    s = ''.join(str(x) for x in sorted(s) )
    ans = str( int(s) + last )
    print ans
