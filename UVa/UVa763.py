import sys



fibo = [1]*110
fibo[1] = 2
for i in range(2, 110):
    fibo[i] = fibo[i - 1] + fibo[i - 2]

def to_dec( s ):
    ans = 0
    for i in range(len(s)):
        if s[-(i + 1)] == '1':
            ans += fibo[i]
    return ans

def to_fib( n ):
    if n == 0:
        return '0'
    idx = len(fibo) - 1
    ans = ['0']*len(fibo)
    while n > 0:
        while fibo[idx] > n:
            idx -= 1
        n -= fibo[idx]
        ans[idx] = '1'
    s = ''.join(ans)[::-1]
    idx = 0
    while idx < len(s) and s[idx] != '1':
        idx += 1
    if idx == len(s):
        return s
    else:
        return s[idx:]
    

a, b = sys.stdin.readline().strip(), sys.stdin.readline().strip()
while a and b:
    print(to_fib(to_dec(a) + to_dec(b)))
    line = sys.stdin.readline()
    if line:
        a = sys.stdin.readline().strip()
        b = sys.stdin.readline().strip()
        print()
    else:
        a, b = None, None
    
