import sys


def get_val( c ):
    if c == ' ':
        return '0'
    elif c == 'o':
        return '1'
    else:
        return ''

line = sys.stdin.readline()
while line:
    if line[0] != '-':
        a = chr(int(''.join(list(map(get_val, line))), 2))
        print(a, end='')
    line = sys.stdin.readline()
