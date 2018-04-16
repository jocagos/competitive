import sys

lines = sys.stdin.readlines()

for line in lines:
    line = line.split()
    a, b = int(line[0]), int(line[1])
    ans = b - a
    if ans >= 0:
        print(ans)
    else:
        print(-ans)
