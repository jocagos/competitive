from datetime import date
from datetime import timedelta
import sys

lines = sys.stdin.readlines()
for line in lines:
    s = line.split(' ')
    n = int(s[0])
    d = int(s[1])
    m = int(s[2])
    y = int(s[3])
    if n or d or m or y:
        dt = date(y, m, d)
        dt = dt + timedelta(days=n)
        tt = dt.timetuple()
        print(tt.tm_mday, tt.tm_mon, tt.tm_year)
