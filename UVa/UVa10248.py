import sys

board = [ [0 for i in range(8)] for i in range(8)]
white = ['P', 'K', 'Q', 'N', 'B', 'R']
black = [i.lower() for i in white]
nums = [str(i) for i in range(1, 9)]
lines = sys.stdin.readlines()
for line in lines:
    if line.isspace():
        continue
    s = line.split('/')
    s[7] = s[7].split()[0]
    r = 0
    for row in s:
        col = 0
        for c in row:
            if c in nums:
                col += int(c)
            else:
                board[r][col] = c
                col += 1
        r += 1
    for i in range(8):
        for j in range(8):
            if board[i][j] in white or board[i][j] in black:
                if board[i][j] in ['k', 'K']:
                    if i - 1 >= 0 and j - 1 >= 0:
                        if board[i-1][j-1] == 0:
                            board[i-1][j-1] = 1
                    if i - 1 >= 0:
                        if board[i-1][j] == 0:
                            board[i-1][j] = 1
                    if i - 1 >= 0 and j + 1 <= 7:
                        if board[i-1][j+1] == 0:
                            board[i-1][j+1] = 1
                    if j - 1 >= 0:
                        if board[i][j-1] == 0:
                            board[i][j-1] = 1
                    if j + 1 >= 0:
                        if board[i][j+1] == 0:
                            board[i][j+1] = 1
                    if i + 1 <= 7 and j - 1 >= 0:
                        if board[i+1][j-1] == 0:
                            board[i+1][j-1] = 1
                    if i + 1 <= 7:
                        if board[i+1][j] == 0:
                            board[i+1][j] = 1
                    if i + 1 <= 7 and j + 1 <= 7:
                        if board[i+1][j+1] == 0:
                            board[i+1][j+1] = 1
                    elif board[i][j] in ['q', 'Q']:
                        
