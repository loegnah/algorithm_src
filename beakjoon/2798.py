import sys
from itertools import combinations

N, M = map(int, sys.stdin.readline().split())
nums = map(int, sys.stdin.readline().split())
ans = 0

for a, b, c in combinations(nums, 3):
    s = a + b + c
    if ans < s <= M:
        ans = s

print(ans)
