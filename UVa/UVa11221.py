import sys
import math
import re

t = int(sys.stdin.readline())
nums = [x*x for x in range(1, 101)]
for _i in range(1, t+1):
    print("Case #", _i, ":", sep='')
    line = re.sub('[^A-Za-z]', '', sys.stdin.readline().strip())
    if len(line) == 0:
        print(0)
        continue
    if len(line) not in nums:
        print("No magic :(")
        continue
    if len(line) == 1:
        print(1)
        continue
    normal = list(line)
    k = int(math.sqrt(len(line)))
    pal = True
    for i in range(len(line)):
        _k = i % k + i // k
        if normal[i] != normal[-i-1] and normal[i] != normal[_k] and normal[i] != normal[-_k-1]:
            pal = False
            break
    if pal:
        print(int(math.sqrt(len(line))))
    else:
        print("No magic :(")
