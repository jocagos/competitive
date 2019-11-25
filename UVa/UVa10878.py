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
        tmp = list(map(get_val, line))
        b = [x for x in tmp if x != '']
        if b:
            a = chr(int(''.join(b), 2))
            print(a, end='')
    line = sys.stdin.readline()
