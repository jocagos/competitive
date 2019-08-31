import sys
import re

lines = sys.stdin.readlines()

for line in lines:
    if line.strip() == "DONE":
        break
    s = re.sub('[^A-Za-z]', '', line).lower()
    if len(s) == 0:
        print("You won't be eaten!")
        continue
    pal = True
    for i in range(len(s)//2+1):
        if s[i] != s[len(s)-1-i]:
            pal = False
            break
    if pal:
        print("You won't be eaten!")
    else:
        print("Uh oh..")
