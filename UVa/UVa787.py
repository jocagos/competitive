import sys


def cntNegs(_list):
    n = 0
    for i in _list:
        if i < 0:
            n += 1
    return n

def getLNeg(_list):
    for i in range(len(_list)):
        if _list[i] < 0:
            return i
    return -1

def getRNeg(_list):
    for i in range(1, len(_list)+1):
        if _list[-i] < 0:
            return len(_list) - i
    return -1

for line in sys.stdin:
    vals = line.split()
    vals = vals[:len(vals)-1]
    vals = [int(n) for n in vals]
    prod = 1
    negs = cntNegs(vals)
    leftNeg, rightNeg = -1, -1
    if negs >= 1:
        leftNeg = getLNeg(vals)
        rightNeg = getRNeg(vals)
        if leftNeg != rightNeg:
            
    for v in vals:
        if v == vals[len(vals)-1]:
            break
        prod *= v
    print(prod)
