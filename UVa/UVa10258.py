import sys

t = int(sys.stdin.readline().strip())
sys.stdin.readline()
lines = sys.stdin.readlines()
l = 0
for i in range(t):
    con = []
    while lines[l].strip() != '':
        line = lines[l].split()
        l += 1
        idx, pr, pe, q = int(line[0]), int(line[1]), int(line[2]), line[3]
        
