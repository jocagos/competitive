import sys


cin = sys.stdin.readline
a = cin()
b, c = int(a), int(a)
for i in range(len(a)):
    if a[i] == '4':
        b += 10 ** (len(a) - i)
        c -= 10 ** (len(a) - i)
