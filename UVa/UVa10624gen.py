N, M = 30, 30
n, m = 1, 2
memo = [-1]*(N + 2)
for i in range(N):
    memo[i] = [-1]*(M + 2)

for m in range(2, M + 1):
    for n in range( 1, m ):
        for nn in range( 10 ** m, 10 ** (m + 1) ):
            digits, able = str(nn), True
            for d in range(1, n + 1 ):
                if not able:
                    break
                if int(digits[0:d]) % d != 0:
                    able = False
            if able:
                memo[n][m] = nn
                break

print('{ ', sep='', end='')
for i in range(1, N + 1):
    print('{ ', sep='', end='')
    for j in range(1, M + 1):
        print('{', i, '{', j, ',', memo[i][j], '} }', end=', ')
