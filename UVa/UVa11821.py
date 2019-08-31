import sys
from decimal import *


def fsum( l ):
    if len(l) == 0:
        return Decimal('0')
    
    if len(l) == 1:
        return l[0]

    n = l[0]
    for i in range(1, len(l)):
        n = n + l[i]
    return n

cont = Context(prec=31)
setcontext(cont)
t = int(sys.stdin.readline())
for i in range(t):
    l = []
    n = Decimal(-1)
    while n != 0:
        n = Decimal(sys.stdin.readline().strip())
        l.append(n)

    ans = fsum(l)
    if ans == ans.to_integral_value():
        print(ans.to_integral_value())
#    elif 'e' in ans.to_eng_string() or 'E' in ans.to_eng_string():
        
    else:
        print(ans)
