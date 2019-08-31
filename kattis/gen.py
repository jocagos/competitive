import random

def genTest():
    with open('test.in', 'w') as f:
        h = str(random.randint(5000, 25000)) + '\n'
        w = str(random.randint(5000, 25000)) + '\n'
        f.write(h + w)
        grid = []
        valid = []
        for i in range(int(h)):
            grid.append([])
            for j in range(int(w)):
                if random.randint(0, 100) > 50:
                    grid[i].append('1')
                    grid[i].append(' ')
                    valid.append( (j, i) )
                else:
                    grid[i].append('0')
                    grid[i].append(' ')
            p = ''.join(grid[i]) + '\n'
            f.write(p)
        f.write('\n')
        start, goal = valid[random.randint(0, len(valid)-1)], valid[random.randint(0, len(valid)-1)]
        f.write(str(start[0]) + ' ' + str(start[1]) + '\n')
        f.write(str(goal[0]) + ' ' + str(goal[1]) + '\n')
        buf = str(int(h) + int(w) + 1) + '\n'
        f.write(buf)

genTest()
