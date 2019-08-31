for i in range(1261, 100000000001):
    d = True
    for j in range(2, 21):
        if i % j != 0:
            d = False
            break
    if d:
        print('num is',i)
        break
