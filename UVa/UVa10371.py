from datetime import datetime
from datetime import timedelta
import sys

n = int(sys.stdin.readline())
for i in range(n):
    line = sys.stdin.readline().split(' ')
    dt = datetime.now()
    if line[0] == "noon" or line[0] == "midnight":
        
