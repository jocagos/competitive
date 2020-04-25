import sys


with open('F2.in', 'w') as f:
    n = 10 ** 5
    c = 10 ** 9
    f.write(str(n) + ' ' + str(c) + '\n')
    for i in range(n):
        f.write(str(i) + ' ')
