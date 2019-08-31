from datetime import datetime
from datetime import timedelta
import sys

t = int(sys.stdin.readline())
dic = { "January":1, "February":2, "March":3, "April":4, "May":5, "June":6, "July":7, "August":8, "September":9, "October":10, "November":11, "December":12 }
l = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

for i in range(1, t+1):
    d = sys.stdin.readline().split('-')
    k = int(sys.stdin.readline())
    dt = datetime(int(d[0]), dic[d[1]], int(d[2]))
    dt = dt + timedelta(days=k)
    print("Case ", i, ": ", dt.year, "-", l[dt.month-1], "-", (dt.day if dt.day >=10 else "0" + str(dt.day)), sep='')
