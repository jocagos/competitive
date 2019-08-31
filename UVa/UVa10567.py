import sys


def isSubSequence(str1,str2,m,n):     
    j = 0
    i = 0
    while j < m and i < n:
        if str1[j] == str2[i]:    
            j = j+1   
        i = i + 1
         
    return j == m
 
str1 = sys.stdin.readline().strip()
queries = int(sys.stdin.readline().strip())
while queries:
    str2 = sys.stdin.readline().split()
    print("Subsequence") if isSubSequence(str1, str2, len(str1), len(str2)) else print("Nope")
    queries -= 1

