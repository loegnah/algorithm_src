import sys

readline = sys.stdin.readline


def fwSum(fwTree, idx):
    ret = 0
    while idx > 0:
        ret += fwTree[idx]
        idx -= (idx & -idx)
    return ret


def fwUpdate(fwTree, idx, diff):
    while idx < len(fwTree):
        fwTree[idx] += diff
        idx += (idx & -idx)


def solve(N, M, nums):
    fwTree = [0] * (N + 1)
    for i, num in enumerate(nums):
        fwUpdate(fwTree, i + 1, num)

    for _ in range(M):
        i, j = map(int, readline().split())
        print(fwSum(fwTree, j) - fwSum(fwTree, i - 1))


def main():
    N, M = map(int, readline().split())
    nums = map(int, readline().split())
    solve(N, M, nums)


main()
