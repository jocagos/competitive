import sys
from decimal import *


cont = Context(prec=100)
setcontext(cont)
CASE = 1
line = sys.stdin.readline().split()
while line:
    a, b = map(Decimal, line)
    print('Case ', CASE, ': ', sep='', end='')
    CASE += 1
    if a < b:
        print('Smaller')
    elif a > b:
        print('Bigger')
    else:
        print('Same')
    line = sys.stdin.readline().split()
