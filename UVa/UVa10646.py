import sys

t = int(sys.stdin.readline())

for i in range(1, t+1):
    line = sys.stdin.readline()
    s = line.split()
    deck = list(s)
    if len(deck) < 52:
        s = list(sys.stdin.readline().split())
        deck = deck + s
    pile = deck[:-25]
    hand = deck[-25:]
    y, x = 0, 0
    for j in range(3):
        top = pile[-1]
        x = int(top[0]) if top[0] >= '2' and top[0] <= '9' else 10
        y += x
        pile = pile[:-(1 + 10 - x)]
    pile = pile + hand
    ans = pile[y-1]
    print("Case ", i, ": ", ans, sep='')
