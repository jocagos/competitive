import sys


line = sys.stdin.readline()
while line:
    b, p, m = line.split()
    b = int(b)
    if b == "0":
        break
    ans = int(p, b) % int(m, b)
    print(ans)
    line = sys.stdin.readline()
