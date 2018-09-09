import sys


part = [1, 1, 2]
m = 100000007
for i in range(9998):
    val, k, n = 0, 1, 2
    while n >= k * (3 * k - 1) / 2:
        t = part[int( n - k * (3 * k - 1) / 2 )]
        val += -1 * t if k - 1 % 2 else t
        val %= m
        k += 1
    k = -1
    while n >= k * (3 * k - 1) / 2:
        t = part[int( n - k * (3 * k - 1) / 2 )]
        val += -1 * t if k - 1 % 2 else t
        val %= m
        k -= 1
    part.append(val)
    # print('metimos', val)
    

part = [0] + part
line = sys.stdin.readline()
while line:
    n = int(line)
    print(part[n])
    line = sys.stdin.readline()
