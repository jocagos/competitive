import sys

lines = sys.stdin.readlines()

for line in lines:
    s = line.split(' ')
    if int(s[0]) == 0 and int(s[1]) == 0 and int(s[2]) == 0 and int(s[3]) == 0:
        break
    l, r = int(s[0]) * 60 + int(s[1]), int(s[2]) * 60 + int(s[3])
    ans = r - l + 1440 if l > r else r - l
    print(ans)
