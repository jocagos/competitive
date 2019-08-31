import sys


trilucas = [0] * 100001
trilucas[1], trilucas[2] = 2, 3
for i in range( 3, 100001 ):
    trilucas[i] = trilucas[i - 1] + trilucas[i - 2] + trilucas[i - 3]
    if trilucas[i] >= 100000007:
        print(i, '=>', trilucas[i])
        trilucas[i] = trilucas[i] % 1000000007
    if trilucas[i] >= ((1 << 64) - 1):
        print('last (index, value) is: (', i, ',', trilucas[i], ')');
        break
