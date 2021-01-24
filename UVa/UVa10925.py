import sys


n, f = map(int, sys.stdin.readline().split())
b = 1
while n:
    total = 0
    for i in range(n):
        total += int(sys.stdin.readline())
    print('Bill #', b, ' costs ', total, ': each friend should pay ', total//f, sep='', end='\n\n')
    b += 1
    n, f = map(int, sys.stdin.readline().split())
