import sys

lines = sys.stdin.readlines()
i = 0
for i in range(len(lines)):
    line = lines[i]
    i += 1
    year = int(line)
    bu, leap, fest = False, False, False
    if year % 400 == 0 or year % 100 != 0 and year % 4 == 0:
        bu = True
        leap = True
        print("This is leap year.")
    if year % 15 == 0:
        fest = True
        print("This is huluculu festival year.")
    if leap and year % 55 == 0:
        fest = True
        print("This is bulukulu festival year.")
    if not leap and not fest:
        print("This is an ordinary year.")
    if not i == len(lines):
        print()
