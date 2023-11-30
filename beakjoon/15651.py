import sys
from itertools import product

readline = sys.stdin.readline
write = sys.stdout.write


def solve():
    global N, M
    nums = [k for k in range(1, N + 1)]
    write("\n".join(list(map(" ".join, product(map(str, nums), repeat=M)))))


N, M = map(int, readline().split())
solve()
