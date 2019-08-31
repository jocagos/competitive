import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
    line = sys.stdin.readline().strip().split()
    a, b = int(line[0]), int(line[1])
    either = (a + b)/2
    other = (a - b)/2
    if other > either:
        either, other = other, either
    if either < 0 or other < 0:
        print("impossible")
    elif either - int(either) > 0 or other - int(other) > 0:
        print("impossible")
    else:
        print(int(either), int(other))
