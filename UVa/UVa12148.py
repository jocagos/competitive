import datetime
import sys

end = True
while end:
    t = int(sys.stdin.readline())
    if t == 0:
        break
    dates = [None] * t
    costs = [0] * t
    diff = datetime.timedelta(days=1)
    cost = 0
    quan = 0
    for i in range(t):
        d, m, y, c = map(int, sys.stdin.readline().split(' '))
        dates[i] = datetime.date( y, m, d )
        costs[i] = c
    for i in range(t-1):
        if dates[i+1] - dates[i] == diff:
            quan += 1
            cost += costs[i+1] - costs[i]
    print(quan, cost)
        
