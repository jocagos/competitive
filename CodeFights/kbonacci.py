import time, sys, collections


def kbonacci(k, n):
    if n < k:
        return str(1)
    if n == k:
        return str(k)
    # using a deque?
    # w = collections.deque([1]*k)
    v = [1]*k
    v.append(k)
    m = n - k
    for _ in range(1, m+1):
        s = 0
        for __ in range(_, _+k):
            s += v[__]
        v.append(s)
    # print(v)
    return str(v[n])

l = sys.stdin.readline().strip().split()
n, k = int(l[0]), int(l[1])
start = time.time()
ans = kbonacci(k, n)
end = time.time()
print("to answer query of n =", n, "and k =", k, "with answer of", ans, "it took", end-start, "seconds.")
