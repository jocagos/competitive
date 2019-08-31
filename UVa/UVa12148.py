import datetime
import sys

end = True
while end:
    t = int(sys.stdin.readline())
    if t == 0:
        break
    dates = []
    diff = datetime.timedelta(days=1)
    cost = 0
    quan = 0
    for i in range(t):
        s = sys.stdin.readline().split(' ')
        d, m, y, c = int(s[0]), int(s[1]), int(s[2]), int(s[3])
        dates.append([datetime.date(y, m, d), c])
    for i in range(len(dates)-1):
        if dates[i+1][0] - dates[i][0] == diff:
            quan += 1
            cost += dates[i+1][1] - dates[i][1]
    print(quan, cost)
        
