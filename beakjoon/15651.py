import sys
from itertools import product

readline = sys.stdin.readline


def solve(N: int, M: int):
    nums = [k for k in range(1, N + 1)]
    for comb in product(nums, repeat=M):
        print(" ".join(map(str, comb)))


def main():
    N, M = map(int, readline().split())
    solve(N, M)


main()
