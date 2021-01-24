import sys


tc = 400 * 100 * 100 * 100
with open('10942-gen.in', 'w') as f:
    f.write(str(tc) + '\n')
    for C in range(400):
        for X in range(100):
            for Y in range(100):
                for Z in range(100):
                    line = str(C) + ' ' + str(X) + ' ' + str(Y) + ' ' + str(Z) + '\n'
                    f.write(line)

print('Tests generated.')
