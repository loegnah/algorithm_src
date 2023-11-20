import sys
from itertools import permutations

readline = sys.stdin.readline


def solve(N: int, M: int):
    nums = [k for k in range(1, N + 1)]
    for item in permutations(nums, M):
        print(" ".join(map(str, item)))


def main():
    N, M = map(int, readline().split())
    solve(N, M)


main()
