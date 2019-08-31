import sys

n = int(sys.stdin.readline())

for _i in range(n):
    board = []
    for i in range(5):
        line = sys.stdin.readline()
        l = [(int(k), False) for k in line.split()]
        board.append(l)
    lines = sys.stdin.readlines()
    nums = [int(i) for SL in lines for i in SL.split()]
    count = 0
    for i in nums:
        # Rows
        for i in range(5)
        count += 1
    print("BINGO after", count, "numbers announced")
