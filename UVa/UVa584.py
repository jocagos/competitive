import datetime
import sys

frames = []

while True:
    line = sys.stdin.readline()
    if line.strip() == "Game Over":
        break;
    s = line.split()
    s[-1] = s[-1].strip()
    for i in s:
        if i == 'X':
            # Strike!
        if i >= '0' and i <= '9':
            # Non-strike non-spare movement
            
