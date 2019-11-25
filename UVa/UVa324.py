import sys
from math import factorial as f
from collections import Counter as C


l = [0]*367
for i in range(len(l)):
    l[i] = C(str(f(i)))
    for k in '0123456789':
        if k not in l[i]:
            l[i][k] = 0
            
n = sys.stdin.readline()
while n != '0':
    n = int(n)
    print(n, '! --', sep='')
    for key in sorted(l[n]):
        print('   (', key, ')', '{:-5}'.format(l[n][key]), sep='', end='')
        if key == '4' or key == '9':
            print()
        else:
            print(' ', end='')
    n = sys.stdin.readline()
