import sys

x = 0
n = int(sys.stdin.readline().strip())
lines = sys.stdin.readlines()
for line in lines:
    line = line.strip()
    if line == '++X' or line == 'X++':
        x += 1
    else:
        x -= 1

print(x)
