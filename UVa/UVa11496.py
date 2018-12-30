import sys


inf = 2000000000
dp = [[-1]*(1<<11)]*11
dist = [[0]*11]*11
x, y = [0]*11, [0]*11
n = 0

# Something's weird with bits in python so I will refrain from trying
# TSP DP again with Python though it is really easy to code
def tsp( pos, mask ):
    if mask == (1 << (n + 1)) - 1: return dist[pos][0]
    if dp[pos][mask] != -1: return dp[pos][mask]
    ans = inf
    for i in range(n + 1):
        if i != pos and not(mask & (1 << i)):
            ans = min( ans, dist[pos][i] + tsp( i, mask | (1 << i) ) )
    dp[pos][mask] = ans
    return ans

tc = int(sys.stdin.readline())
for _ in range(tc):
    X, Y = map(int, sys.stdin.readline().split())
    x[0], y[0] = map(int, sys.stdin.readline().split())
    n = int(sys.stdin.readline())
    for i in range(1, n + 1):
        x[i], y[i] = map(int, sys.stdin.readline().split())

    dist = [[abs(x[i] - x[j]) + abs(y[i] - y[j]) for j in range(n + 1)] for i in range(n + 1)]
    # for i in range(n + 1):
    #     for j in range(n + 1):
    #         dist[i][j] = abs( x[i] - x[j] ) + abs( y[i] - y[j] )
    dp = [[-1]*(1<<11)]*11
    print('The shortest path has length', tsp( 0, 1 ))
        
