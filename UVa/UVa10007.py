import sys


f = [1]*604
memo = [-1]*604
for i in range(2, 604):
    f[i] = f[i - 1] * i

def cat(n):
    global memo
    global f
    if memo[n] == -1:
        memo[n] = f[2*n] // f[n] // (n + 1)
    return memo[n]


line = sys.stdin.readline()
while line:
    n = int(line)
    if n == 0:
        break
    print(cat(n))
    line = sys.stdin.readline()
