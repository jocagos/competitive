import sys


line = sys.stdin.readline()
print('import sys\n\n', end='')
print('l = [', end='')
while line:
    line = line.split(' ')
    print((int(line[1]) % 100000007), end=', ')
    line = sys.stdin.readline()

print('}')
print('line = sys.stdin.readline()')
print('while line:')
print('\tprint(l[int(line)])')
print('\tline = sys.stdin.readline()')
