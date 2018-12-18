import sys


sys.setrecursionlimit(1000000)
dp = [[-1]*310]*310
dp[0] = [0]*310
dp[0][0] = 1
for i in range(1, 305):
    for j in range(0, 305):
        if i <= j: dp[i][j] = dp[i][j-i] + dp[i-1][j]
        else: dp[i][j] = dp[i-1][j]

line = sys.stdin.readline()
while line:
    line = line.split()
    ans = -1
    if len(line) == 1:
        n = int(line[0])
        ans = dp[n][n]
    elif len(line) == 2:
        n, q = map(int, line)
        ans = dp[n][q]
    else:
        n, l, r = map(int, line)
        ans = dp[n][r] - dp[n][l]
    print(ans)
    line = sys.stdin.readline()

