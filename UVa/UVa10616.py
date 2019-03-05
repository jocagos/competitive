import sys


def ans( idx, _sum, rem ):
    if rem == m and _sum == 0: return 1
    if rem == m and _sum != 0: return 0
    if idx == n: return 0
    if dp[idx][_sum][rem] == -1:
        dp[idx][_sum][rem] = ans( idx + 1, _sum % d, rem ) + ans( idx + 1, (_sum + a[idx] ) % d, rem + 1 )
    return dp[idx][_sum][rem]

s = 1
dp = [[[-1]*210]*210]*25
sys.setrecursionlimit(100000)
n, q = map( int, sys.stdin.readline().split() )
d, m = 0, 0
a = []
while n != 0 and q != 0:
    a = [0] * n
    print('SET ', s, ':', sep='')
    s += 1
    for i in range(n): a[i] = int(input())
    for i in range(q):
        d, m = map( int, sys.stdin.readline().split() )
        dp = [[[-1]*210]*210]*25
        print('QUERY ', i + 1, ': ', ans( 0, 0, 0 ), sep='')
    n, q = map( int, sys.stdin.readline().split() )
