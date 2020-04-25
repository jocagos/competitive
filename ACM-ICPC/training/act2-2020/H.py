import sys


def get_closest_match( n ):
    val = (3 * n + 1) * n // 2
    while val % 4 != 0:
        n += 1
        val += 3 * n - 1
    return n

n = int(sys.stdin.readline())
print(get_closest_match(n))
