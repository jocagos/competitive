import sys

lines = sys.stdin.readlines()
for line in lines:
    suits = { "S":[[],0, False], "H":[[],0, False], "D":[[],0, False], "C":[[],0, False] }
    s = line.split()
    for t in s:
        suits[t[1]][0].append(t[0])
    
    handB = 0
    for suit in suits:
        if 'A' in suits[suit][0]:
            suits[suit][2] = True
            suits[suit][1] += 4
        if 'K' in suits[suit][0]:
            suits[suit][1] += 3
            if len(suits[suit][0]) == 1:
                suits[suit][1] -= 1
            if len(suits[suit][0]) > 1:
                suits[suit][2] = True
        if 'Q' in suits[suit][0]:
            suits[suit][1] += 2
            if len(suits[suit][0]) < 3:
                suits[suit][1] -= 1
            if len(suits[suit][0]) > 2:
                suits[suit][2] = True
        if 'J' in suits[suit][0]:
            suits[suit][1] += 1
            if len(suits[suit][0]) < 4:
                suits[suit][1] -= 1
        handB += suits[suit][1]
        if len(suits[suit][0]) == 2:
            suits[suit][1] += 1
        if len(suits[suit][0]) == 1:
            suits[suit][1] += 1
        if len(suits[suit][0]) == 0:
            suits[suit][1] += 1

    hand = suits['S'][1] + suits['H'][1] + suits['D'][1] + suits['C'][1]
    stop = suits['S'][2] and suits['H'][2] and suits['D'][2] and suits['C'][2]
    
    # Debug
    for suit in suits:
        print("Suit:", suit, "\n", suits, end='\n\n')
    # End

    if handB >= 16 and stop:
        print("BID NO-TRUMP")
    elif hand >= 14:
        mx = max(suits['H'][1], suits['S'][1], suits['D'][1], suits['C'][1])
        if mx == suits['S'][1]:
            print("BID S")
        elif mx == suits['H'][1]:
            print("BID H")
        elif mx == suits['D'][1]:
            print("BID D")
        elif mx == suits['C'][1]:
            print("BID C")
    else:
        print("PASS")
