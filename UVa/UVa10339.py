import sys

lines = sys.stdin.readlines()

for line in lines:
    line = line.split(' ')
    k, m = int(line[0]), int(line[1])
    diff = k - m if k - m > 0 else m - k
    res = ( 43200 * (86400 - k) // diff ) % 43200 + 30
    print(k," ", m," ", 12 if res // 3600 % 12 == 0 else (res // 3600 % 12 if res // 3600 % 12 >= 10 else "0" + str(res // 3600 % 12)),":", res // 60 % 60 if res // 60 % 60 >= 10 else "0" + str(res // 60 % 60), sep="")
