import sys
from itertools import permutations

readline = sys.stdin.readline
write = sys.stdout.write


def solve():
    global N, M, nums
    nums.sort()
    for prm in permutations(nums, M):
        write(' '.join(map(str, prm)) + '\n')


N, M = map(int, readline().split())
nums = list(map(int, readline().split()))
solve()
