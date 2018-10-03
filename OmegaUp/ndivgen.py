#!/usr/bin/env python3
import os
#--- set your code directory below
dr = "./"
#--- set the desired (base) name extension and shebang below (leave it ""if you don't want an automatically set shebang)
name_initial = "testndiv"
extension = ".in"
#---

existing = os.listdir(dr)
for n in range(0, 1000001):
    file = dr + name_initial + str(n) + extension
    with open(file, "wt") as out:
        out.write(str(n)+'\n')
