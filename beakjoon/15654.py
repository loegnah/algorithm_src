import sys
from itertools import permutations

readline = sys.stdin.readline


def solve():
    global M, nums
    nums.sort()
    answers = list(map(' '.join, permutations(map(str, nums), M)))
    print('\n'.join(answers))


N, M = map(int, readline().split())
nums = list(map(int, readline().split()))
solve()
