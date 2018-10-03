import sys

def getMinWinner(deck, threshold):
    winner = None
    for i in deck:
        if i > threshold:
            return i
    return -1

while True:
    deck = list(range(1, 53))
    line = sys.stdin.readline()
    s = line.split()
    if int(s[0]) == 0:
        break
    princess = [int(s[i]) for i in range(3)]
    for i in princess:
        if i in deck:
            deck.remove(i)
    prince = [int(s[i+3]) for i in range(2)]
    for i in prince:
        if i in deck:
            deck.remove(i)
    perms = prince + princess
    perms = list(reversed(sorted(perms)))
    if perms[0] in prince and perms[1] in prince:
        print(min(deck))
    elif max(prince) == perms[0]:
        if min(prince) == perms[2]:
            princess.remove(getMinWinner(princess, min(prince)))
            print(getMinWinner(deck, max(princess)))
        else: # elif min(prince) == perms[3]:
            print(getMinWinner(deck, max(princess)))
    elif max(prince) == perms[1]:
        if min(prince) == perms[2]:
            princess.remove(max(princess))
            print(getMinWinner(deck, max(princess)))
        else: # min(prince) == perms[3]:
            print(-1)
#        else:
#            print(-1)
    else:
        print(-1)
