import sys



pow2 = [1]*120
m = 17
for i in range(1, 120):
    pow2[i] = pow2[i - 1]*2
T = int(sys.stdin.readline())
for _ in range(T):
    N, K = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    ans, diff = 1, pow2[K - 1]
    if N > K + 2:
        e = pow2[N - K - 1]
        for i in range(K):
            ans = (pow( a[i], e - diff, m ) * ans) % m
            # print('multiplying by', pow( a[K-i-1], e - diff, m ))
            diff = diff // 2
    elif N == K + 2:
        for i in range(K):
            ans = ans * a[i] % m * a[i] % m
    elif N == K + 1:
        for i in range(K):
            ans = ans * a[i] % m
    else:
        ans = a[N-1] % m
    print(ans)
