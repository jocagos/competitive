import sys


val = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9 }
i = 10
for c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
    val[c] = i
    i += 1
line = sys.stdin.readline()
while line:
    a, b = line.split()
    max_left, max_right = 1, 1
    for c in a:
        max_left = max( max_left, val[c] )
    for c in b:
        max_right = max( max_right, val[c] )
    finish_it = False
    for left in range(max_left + 1, 37):
        if finish_it:
            break
        for right in range(max_right + 1, 37):
            if finish_it:
                break
            if int(a, left) == int(b, right):
                print(a, ' (base ', left, ') = ', b, ' (base ', right, ')', sep='')
                finish_it = True
                break
    if not finish_it:
        print(a, ' is not equal to ', b, ' in any base 2..36', sep='')
            
    
    line = sys.stdin.readline()
