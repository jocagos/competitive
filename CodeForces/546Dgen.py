import random


N = 1000000
MAX = 5000000
with open('546D.in', 'w') as f:
    f.write( str(N) + '\n' )
    for _ in range(N):
        a, b = random.randint(1, MAX), random.randint(1, MAX)
        cont = str(a) + ' ' + str(b) + '\n'
        f.write(cont)

