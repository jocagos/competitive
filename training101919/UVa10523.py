import sys

memo = [-1]*20
_A = [-1]*20
for i in range(16):
    memo[i] = [-1]*180
    _A[i] = [1]*20
memo[0][0] = 0
for i in range(1, 20):
    for j in range(1, 20):
        _A[i][j] = _A[i][j - 1] * i

for A in range( 1, 20 ):
    memo[A][0] = 0
    for i in range( 1, len(memo) ):
        memo[A][i] = memo[A][i - 1] + i * _A[A][i]

line = sys.stdin.readline()
while line:
    A, n = map( int, line.split() )
    print(memo[A][n])
    line = sys.stdin.readline()
