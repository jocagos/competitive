import sys


d = { 'A':1, 'B':2, 'C':3, 'D':4, 'E':5, 'F':6, 'G':7, 'H':8, 'I':9, 'J':10, 'K':11, 'L':12, 'M':13, 'N':14, 'O':15, 'P':16, 'Q':17, 'R':18, 'S':19, 'T':20, 'U':21, 'V':22, 'W':23, 'X':24, 'Y':25, 'Z':26 }
t = int(sys.stdin.readline())
if t == 0:
    # str to int
    line = sys.stdin.readline()
    val = 0
    exp = 0
    for c in reversed(line.strip()):
        val += d[c] ** exp
        exp += 1
elif t == 1:
    # int to str
    line = sys.stdin.readline()
    n = int(line)
    
