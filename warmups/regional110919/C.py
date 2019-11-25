import sys


n = int(sys.stdin.readline())
s = set()
while n:
    line = sys.stdin.readline()
    left, right = line.split('@')
    left = [c for c in left if c != '.']
    left = ''.join(left)
    if '+' in left:
        left = left[:left.find('+')]
    s.add( left + '@' + right )
    n -= 1
print(len(s))
