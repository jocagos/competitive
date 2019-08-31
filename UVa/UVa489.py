import sys

win = 'You win.'
lose = 'You lose.'
chicken = 'You chickened out.'

t = int(sys.stdin.readline())
while t != -1:
    print("Round", t)
    mistakes = []
    word = sys.stdin.readline().split()[0]
    guess = sys.stdin.readline().split()[0]
    t = int(sys.stdin.readline())
    g = [False] * len(word)
    w = False
    for c in guess:
        if c not in word and c not in mistakes:
            mistakes.append(c)
        if w and len(mistakes) <= 7:
            break
        for i in range(len(word)):
            if word[i] == c:
                g[i] = True
            if False not in g:
                w = True
    if w and len(mistakes) < 7:
        print(win)
    elif len(mistakes) >= 7:
        print(lose)
    elif not w and len(mistakes) < 7:
        print(chicken)
