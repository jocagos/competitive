s = input()

s = s.strip()
s = s.split('+')
s = sorted(s)
s = '+'.join(s)
print(s)