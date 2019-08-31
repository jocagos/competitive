import sys


dp = [[-1]*110]*25
# this thing was needed because some cases use a lot of the stack
# as the dp is top-down
sys.setrecursionlimit(100000)
def ans( i, w ):
    # print('got here with i =', i, 'and w =', w, file=sys.stderr)
    if w <= 0 or i == len(l): return 0
    if dp[i][w] != -1: return dp[i][w]
    if l[i] > w:
        dp[i][w] = ans( i + 1, w )
        return dp[i][w]
    # Lmao if you change this shit to something along the lines of:
    # `max( ans( i + 1, w ), l[i] + ans( i + 1, w - l[i] ) )`
    # suddenly you can't solve some cases like 20 times 1
    # this is mostly due to the fact that it will try to skip them first
    # though it can choose them, thus getting to the last value and
    # forgetting about picking them back
    dp[i][w] = max( l[i] + ans( i + 1, w - l[i] ), ans( i + 1, w ) )
    return dp[i][w]

n = int(sys.stdin.readline())
l = []
for _ in range(n):
    l = list(int(x) for x in sys.stdin.readline().split())
    s = sum(l)
    if s % 2 == 1:
        print('NO')
    else:
        a = ans( 0, s // 2 )
        if a == s // 2:
            print('YES')
        else:
            print('NO')
        dp = [[-1]*110]*25
