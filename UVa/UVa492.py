import sys


line = sys.stdin.readline()
vowels = ['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U']
while line:
    s = line.split()
    print('line:', line)
    print('s:', s)
    for t in s:
        if t[0] in vowels: print(t, 'ay', sep='', end='')
        elif t == '': print(' ', sep='', end='')
        else: print(t[1:], t[0], 'ay', sep='', end='')
        if t != s[-1]: print(' ', end='')
    print()
    line = sys.stdin.readline()
