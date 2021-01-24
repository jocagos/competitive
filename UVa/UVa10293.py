import sys, re


counts = [0] * 33
prev = ''
line = sys.stdin.readline().strip()
while line:
    if line[0] == '#':
        for i in range(1, 33):
            if counts[i]:
                print(i, counts[i])
        print()
        counts = [0] * 33
    else:
        if prev == '#' and line == '':
            break
        while line[-1] == '-':
            line = line[:len(line)-1] + sys.stdin.readline().strip()
        line = re.split("[;,.?!: ]", line)
        for word in line:
            L = len(word.translate({ord(i): None for i in "-'"}))
            # print('>', word,'< has lenght', L)
            counts[L] += 1
    prev = line
    line = sys.stdin.readline().strip()
