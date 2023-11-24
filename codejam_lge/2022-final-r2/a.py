from sys import stdin
from math import comb

readline = stdin.readline


def decideIsUp(a, b):
    return 1 if a < b else 0 if a == b else -1


for _ in range(int(readline())):
    n = int(readline())
    A = list(map(int, readline().split()))
    idx, preIsUp, zigzagStart, ans = 1, 0, 0, 0

    while idx < n:
        isUp = decideIsUp(A[idx - 1], A[idx])
        if isUp == 0:
            ans += comb(idx - zigzagStart, 2)
            zigzagStart = idx
        elif isUp == preIsUp:
            ans += comb(idx - zigzagStart, 2)
            zigzagStart = idx - 1

        preIsUp = isUp
        idx += 1
        if idx == n:
            ans += comb(idx - zigzagStart, 2)
    print(ans)
