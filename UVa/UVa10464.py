import sys
from decimal import *


cont = Context(prec=2000)
setcontext(cont)
n = int(sys.stdin.readline())
for i in range(n):
    line = sys.stdin.readline().split()
    left, right = Decimal(line[0]), Decimal(line[1])
    ans = left + right
    ans = ans.normalize()
    if ans % 1 == 0:
        print(str(ans) + '.0')
    else:
        print(ans)
    
