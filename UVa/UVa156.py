import sys
from collections import Counter

def getWords(lines):
    for line in lines:
        for word in line.split():
            if word != "#" and word != "":
                yield word

lines = [line.strip() for line in sys.stdin.readlines()]
words = {}
for word in sorted(getWords(lines)):
    k = ''.join(sorted(list(word.lower()))) 
    if k in words:
        words[k].append(word)
    else:
        words[k] = [word]
        
vals = []
for k in words:
    if len(words[k]) == 1:
        vals.append(words[k][0])

for word in sorted(vals):
    print(word)
