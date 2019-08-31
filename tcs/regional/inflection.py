import sys


x = [-2.0] * 10000
y = [-2.0] * 10000
dy = [-2.0] * 10000
d2y = [-2.0] * 10000
line = sys.stdin.readline()
s = line.split(',')
x = [float(i) for i in s]
c = len(x)
line = sys.stdin.readline()
s = line.split(',')
y = [float(i) for i in s]
dy = [y[i+1] - y[i] for i in range(c-1)]
d2y = [dy[i+1] - dy[i] for i in range(c-2)]

