import sys

lines = sys.stdin.readlines()
f = []
s = []
for i in range(3):
    for c in lines[i]:
        f.append(c)
for i in range(3, 6):
    for c in lines[i]:
        s.append(c)

t = zip(f, s)
for i in t:
    print("(", ord(i[0]), "=>", ord(i[1]), ") => ", i, sep='')
