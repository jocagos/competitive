import sys, math, random


f = lambda a : str(a) + ' '
for i in range(1, 2 * 10 ** 5 ):
    d = len(str(i))
    sys.stdout.writelines( str(d) + '\n' )
    sys.stdout.writelines( str(i) + '\n' )
    code = list(map( f, [ random.randint(1, 9) for i in range( 9 ) ] ))
    code[-1] += '\n'
    sys.stdout.writelines( code )
