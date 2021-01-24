import sys


tc = int(sys.stdin.readline())
for CASE in range(1, tc + 1):
    n, l = map(int, sys.stdin.readline().split())
    mangos = list(map(int, sys.stdin.readline().split()))
    lims = list(map(int, sys.stdin.readline().split()))
    ans = ''
    if sum(mangos) > l:
        ans = 'No'
    else:
        for i in range(n):
            if lims[i] < mangos[i]:
                ans = 'No'
                break
        if ans == '':
            ans = 'Yes'
    print('Case ', CASE, ': ', ans, sep='')
