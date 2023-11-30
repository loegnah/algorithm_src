import sys
from itertools import product

readline = sys.stdin.readline
write = sys.stdout.write


def solve(N: int, M: int):
    nums = [k for k in range(1, N + 1)]
    for comb in product(nums, repeat=M):
        write(" ".join(map(str, comb)) + '\n')


def main():
    N, M = map(int, readline().split())
    solve(N, M)


main()
