import sys


def distTo(_from, _to):
    return _from - _to if _from >= _to else _to - _from - 1

n = sys.stdin.readline().strip()
if int(n) % 25 == 0:
    print(0)
    exit(0)
l = list(n)
zero, secondZero, two, five, seven = False, False, False, False, False
d = dict(zip([0, -1, 2, 5, 7], [0]*5))
vals = []
for i in range(1, len(l)+1):
    if (zero and secondZero) or (zero and five) or (two and five) or (five and seven):
        vals = [(x, d[x]) for x in d if d[x] > 0]
        break
    if zero and l[-i] == '0':
        d[-1] = i - 1
        secondZero = True
    if not zero and l[-i] == '0':
        d[0] = i - 1
        zero = True
    if not five and l[-i] == '5':
        d[5] = i - 1
        five = True
    if not two and l[-i] == '2':
        d[2] = i - 1
        two = True
    if not seven and l[-i] == '7':
        d[7] = i - 1
        seven = True

if zero and secondZero:
    vals = [(x, d[x]) for x in d if x in [0, -1]]
elif zero and five:
    vals = [(x, d[x]) for x in d if x in [0, 5]]
elif two and five:
    vals = [(x, d[x]) for x in d if x in [2, 5]]
elif five and seven:
    vals = [(x, d[x]) for x in d if x in [5, 7]]

sum = 0
print("vals:",vals)
if len(vals) < 2:
    print(-1)
# Case 1
elif zero and (five or secondZero):
    daMin = vals[0] if vals[0][1] < vals[1][1] else vals[1]
    daMax = vals[1] if vals[0][1] < vals[1][1] else vals[0]
    if daMin[0] != 0 and (vals[0][1] != 0 and vals[1][1] != 1) and (vals[0][1] != 1 and vals[1][1] != 0):
        sum += 1
    sum += distTo(vals[0][1], 0) + distTo(vals[1][1], 1) if vals[0][0] == 0 else distTo(vals[1][1], 0) + distTo(vals[0][1], 1)
    print(sum)
elif five and (two or seven):
    daMin = vals[0] if vals[0][1] < vals[1][1] else vals[1]
    daMax = vals[1] if vals[0][1] < vals[1][1] else vals[0]
    if daMin[0] != five and (vals[0][1] != 0 and vals[1][1] != 1 and vals[0][1] != 1 and vals[1][1] != 0):
        sum += 1
    sum += distTo(vals[0][1], 0) + distTo(vals[1][1], 1) if vals[0][0] == 5 else distTo(vals[1][1], 0) + distTo(vals[0][1], 1)
    print(sum)
# elif vals[0][0] == -1:
#    if vals[0][1] == 0 or vals[1][1] == 0:
#        sum = vals[1][1] - 1 if vals[0][1] == 0 else vals[0][1] - 1
#    else:
        
# elif vals[0][0] == 5 and vals[0][1] == 0 or vals[0][0] == 0 and vals[0][1] == 0:
#    sum = vals[1][1]
#    print(sum)
# elif vals[1][0] == 5 and vals[1][1] == 0 or vals[1][0] == 0 and vals[1][1] == 0:
#    sum = vals[0][1]
#    print(sum)
# else:
#    sum = vals[0][1] + vals[1][1] - 1
#    print(sum)
#    if vals[0][0] == vals[1][0]:
#        sum = vals[0][1] + vals[1][1] - 1
#    elif vals[0][0] == 0 or vals[1][0] == 0:
#        sum = vals[0][1] + vals[1][1] - 1
#    else:
#
