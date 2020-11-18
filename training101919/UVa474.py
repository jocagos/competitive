import sys, decimal


memo = [Decimal(-1)] * 1000100
memo[0] = Decimal(1)
for i in range( 1, len( memo ) ):
    

line = sys.stdin.readline()
while line:
    n = int(line)
    
    line = sys.stdin.readline()
