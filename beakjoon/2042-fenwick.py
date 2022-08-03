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


N, M, K = map(int, readline().split())
nums = [int(readline()) for _ in range(N)]
tree = [0] * (N + 1)

for i, n in enumerate(nums):
    fwUpdate(tree, i + 1, n)

for _ in range(M + K):
    a, b, c = map(int, readline().split())

    if a == 1:
        df = c - nums[b - 1]
        nums[b - 1] = c
        fwUpdate(tree, b, df)
    elif a == 2:
        print(fwSum(tree, c) - fwSum(tree, b - 1))
