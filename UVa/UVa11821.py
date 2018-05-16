import sys
from decimal import *


def _abs( s ):
    if type(s) == type(''):
        return int(s) if int(s) > 0 else -1 * int(s)

def fsum( l ):
    if len(l) == 0:
        return Decimal('0')
    
    if len(l) == 1:
        return l[0]

    n = l[0]
    for i in range(1, len(l)):
        n = n + l[i]
    return n

def to_real_str( eng_str ):
    s = eng_str.split('E')
    left, right = s[0], s[1]
    if '.' in left:
        return 0
    else:
        if right[0] == '-':
            for i in range(_abs(right)):
                left = '0' + left
            left = '-0.' + left
        else:
            for i in range(_abs(right)):
                left += '0'
        return 0


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
