import sys


def F(c):
    if c == 'V':
        return '0'
    elif c == 'U':
        return '1'
    elif c == 'C':
        return '2'
    elif c == 'D':
        return '3'

n = int(sys.stdin.readline())
print('COWCULATIONS OUTPUT')
while n:
    A, B = sys.stdin.readline(), sys.stdin.readline()
    ops = [0] * 3
    for i in range(3):
        ops[i] = sys.stdin.readline().strip()
    C = sys.stdin.readline()
    A = list(A)
    B = list(B)
    C = list(C)
    A = [F(a) for a in A]
    A = [a for a in A if a]
    A = ''.join(A)
    B = [F(b) for b in B]
    B = [b for b in B if b]
    B = ''.join(B)
    C = [F(c) for c in C]
    C = [c for c in C if c]
    C = ''.join(C)
    a = int(A, 4)
    b = int(B, 4)
    for op in ops:
        if op == 'A':
            b = a + b
        elif op == 'L':
            b = b * 4
        elif op == 'R':
            b = b // 4
    c = int(C, 4)
    if b == c:
        print('YES')
    else:
        print('NO')
    n -= 1
print('END OF OUTPUT')
