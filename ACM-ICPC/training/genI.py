# data generator for I to check a bug from `I.py`
import sys


vals = set()
for i in range( 1, 1001 ):
    for j in range( 1, 1001 ):
        if i + j <= 2000 and (i + j) not in vals:
            print(i, j)
            vals.add( i + j )
