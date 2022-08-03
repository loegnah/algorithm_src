import sys
from math import sqrt

readline = sys.stdin.readline


def solve():
    n = int(readline())
    if n == 1: return

    sqrt_n, div, ans = int(sqrt(n)), 2, []

    while div <= sqrt_n:
        if not n % div:
            print(div)
            n /= div
        else:
            div += 1
    if int(n) != 1:
        print(int(n))


solve()
