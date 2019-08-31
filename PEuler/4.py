def isPalindrome( n ):
    s = str(n)
    p = True
    for i in range( len( s ) // 2 ):
        if s[i] != s[-i-1]:
            p = False
            break
    return p

pals = []
for i in range(999, 0, -1):
    for j in range(999, 0, -1):
        if isPalindrome( i * j ):
            pals.append( i * j )

pals = sorted(pals)
print(pals[-1])
