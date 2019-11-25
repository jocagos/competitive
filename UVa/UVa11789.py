import sys


line = sys.stdin.readline()
while line:
    n = int(line)
    if n == 0:
        break
    print('1' if n % 17 == 0 else '0')
    line = sys.stdin.readline()
