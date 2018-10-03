import sys
import math

lines = sys.stdin.readlines()
mods = [0, 3, 2, 1]
for line in lines:
    n = int(line.strip())
    if n == 0:
        break
    sheets = int(math.ceil(n/4))
    if n == 1:
        print("Printing order for 1 pages:", "Sheet 1, front: Blank, 1", sep='\n')
        continue
    vals = list(range(1, n+1)) + ['Blank']*mods[n%4]
    f, l = 0, len(vals)-1
    print("Printing order for", n, "pages:")
    for i in range(1,len(vals)//4 + 1):
        print("Sheet ", i, ", front: ", vals[l], ", ", vals[f], sep='')
        l -= 1
        f += 1
        print("Sheet ", i, ", back : ", vals[f], ", ", vals[l], sep='')
        l -= 1
        f += 1
