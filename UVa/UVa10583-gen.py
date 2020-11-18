import random


max_n = 50000
max_m = int(max_n * (max_n - 1) / 2)
with open('10583.in2', 'w') as f:
    f.write(str(max_n) + ' ' + str(max_n - 1) + '\n')
    for i in range(max_n - 1):
        f.write('1 ' + str(i + 2) + '\n')

