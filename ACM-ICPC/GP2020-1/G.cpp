ar = input().split()
ar2 = []
sum = 0

for i in range(18):
    ar2 = input()
    if ar2 == "hole in one":
        sum = sum + 1
    elif ar2 == "condor":
        sum = sum + (int(ar[i]) - 4)
    elif ar2 == "albatross":
        sum = sum + (int(ar[i]) - 3)
    elif ar2 == "eagle":
        sum = sum + (int(ar[i]) - 2)
    elif ar2 == "birdie":
        sum = sum + (int(ar[i]) - 1)
    elif ar2 == "par":
        sum = sum + int(ar[i])
    elif ar2 == "bogey":
        sum = sum + (int(ar[i]) + 1)
    elif ar2 == "double bogey":
        sum = sum + (int(ar[i]) + 2)
    else:
        sum = sum + (int(ar[i]) + 3)

print(sum)
