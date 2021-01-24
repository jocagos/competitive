import sys


line = sys.stdin.readline()
while line:
    r, p = map(int, line.split())
    points = list(map(int, sys.stdin.readline().split()))
    r -= 1
    for i in range(r):
        tmp = list(map(int, sys.stdin.readline().split()))
        points += tmp
        # points = [x + y for x, y in zip(points, tmp)]
    mx, idx = points[-1], len(points)-1
    for i in range(len(points) - 2, -1, -1):
        if points[i] > mx:
            mx, idx = points[i], i
    print(idx + 1)
    line = sys.stdin.readline()
