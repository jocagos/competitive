from math import factorial as fact
import sys


comb = lambda n, k: int(fact(n) / (fact(k) * fact(n - k)))

def main():
    R, N = map(int, sys.stdin.readline().split())
    D = int(N // R)
    dist = 1
    ans = 1

    if N % R != 0:
        while dist < R:
            ans *= comb(N, D)
            N -= D
            dist += 1
    else:
        ans = 1
        nn, kk = N - 1, R - 1
        while nn != kk:
            ans *= comb( nn, kk )
            nn -= R

    print(int(ans))

if __name__ == '__main__':
    main()
