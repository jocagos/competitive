import datetime
import sys

t = int(sys.stdin.readline())
wd = { 0:"Monday", 1:"Tuesday", 2:"Wednesday", 3:"Thursday", 4:"Friday", 5:"Saturday", 6:"Sunday" }

for i in range(t):
    line = sys.stdin.readline()
    s = line.split(' ')
    m, d = int(s[0]), int(s[1])
    dt = datetime.date(2011, m, d)
    print(wd[dt.weekday()])
