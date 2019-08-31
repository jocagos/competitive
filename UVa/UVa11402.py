import sys


t = int(sys.stdin.readline())
for i in range(1, t+1):
    m = int(sys.stdin.readline())
    n = 0
    pirates = []
    while m:
        times = int(sys.stdin.readline())
        pattern = sys.stdin.readline()
        n += len(pattern) * times
        pattern = pattern * times
        pirates.append(pattern)
        
        m -= 1
    print('Case ', t, ':', sep='', end='\n')
    
