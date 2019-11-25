import sys


def get_code( c, i ):
    a = c + i
    if a <= ord('Z'):
        return a
    else:
        return a - 25
line = sys.stdin.readline()
d = []
while line != '#':
    d.append(line)
    line = sys.stdin.readline()

msg = sys.stdin.readline()
msgs = [msg]*26
for i in range(1, 26):
    vals = [chr(get_code(ord(x), i)) for x in msgs[i]]
    msgs[i] = ''.join(vals)
matches = [0]*26
for i in range(26):
    msg = msgs[i]
    for word in d:
        if word in msg:
            matches[i] += 1
idx = -1
ma = 0
for i in range(len(matches)):
    if matches[i] > ma:
        ma = matches[i]
        idx = i

    
