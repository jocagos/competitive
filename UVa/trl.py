import sys

for i in range(5):
    l = sys.stdin.readline()
    print("Line by line:", l)
lines = sys.stdin.readlines()
for line in lines:
    print("readlines:", line)

