import sys
s = sys.stdin.readlines()
for line in s:
    if int(line) % 6 == 0:
        print("Y")
    else:
        print("N")
