import sys


n = int(sys.stdin.readline())
dp = [-1] * 100100
bucket = dict()
nums = list(map(int, sys.stdin.readline().split() ))
for k in nums:
    bucket[k] += 1
pairs = 
