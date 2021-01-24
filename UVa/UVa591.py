import sys


n = int(sys.stdin.readline().strip())
case = 1
while n != 0:
    heights = list(map(int, sys.stdin.readline().split()))
    total = sum(heights)
    avg = total // len(heights)
    movs = 0
    for H in heights:
        movs += abs(H - avg)
    movs //= 2
    print('Set #', case, sep='')
    print('The minimum number of moves is ', movs, '.', sep='', end='\n\n')
    case += 1
    n = int(sys.stdin.readline().strip())
    
