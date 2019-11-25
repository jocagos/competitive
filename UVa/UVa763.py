import sys


def bin_search(x):
    lo, hi = 0, len(fibo)
    mi = int((lo + hi) / 2)
    prev_lo, prev_hi = None, None
    while lo < hi:
        if prev_lo is None:
            prev_lo = lo
        if prev_hi is None:
            prev_hi = hi
        if lo == prev_lo and hi == prev_hi:
            break
        if fibo[mi] == x:
            return mi
        if fibo[mi] < x:
            lo, mi = mi, int((mi + hi)/2)
        else:
            mi, hi = int((lo+mi)/2), mi
    if mi != 0 and fibo[mi] <= x:
        return mi
    return -1

fibo = [1]*110
fibo[1] = 2
for _ in range(2, 110):
    fibo[_] = fibo[_ - 1] + fibo[_ - 2]

def to_dec( s ):
    ans = 0
    for i in range(len(s), 0, -1):
        if s[-i] == '1':
            ans += fibo[i]
    return ans

def to_fib( n ):
    ans = ['0']*110
    max_len = -1
    while n:
        idx = bin_search(n)
        n -= fibo[idx]
        ans[idx] = '1'
        max_len = max(idx, max_len)
    return ''.join(ans[:(max_len + 1)])

lines = sys.stdin.readlines()
a, b = None, None
count = 0
for line in lines:
    if line is not '':
        if a is None:
            a = line
        else:
            b = line
    else:
        a, b = map( to_dec, [a, b] )
        c = a + b
        a, b = None, None
        count += 1
        print(to_fib(c))
        print()
if (len(lines) + 1) // 3 > count:
    a, b = map( to_dec, [a, b] )
    print(to_fib(a + b))


    
