import sys
from itertools import permutations

readline = sys.stdin.readline

T = int(readline())
for _ in range(T):
    N, M = map(int, readline().split())
    s = [[0] * (N + 1) for _ in range(N + 1)]
    for i in range(M):
        v, a, b = map(int, readline().split())
        s[a][b] += v

    mxScore = -1
    mxCase = 0
    for items in permutations(range(1, N + 1), N):
        shown = [False] * (N + 1)
        score = 0
        for i in items:
            for n in range(1, N + 1):
                if shown[n]:
                    continue
                score += s[i][n]
            shown[i] = True
        if mxScore < score:
            mxScore = score
            mxCase = 1
        elif mxScore == score:
            mxCase += 1

    print(mxScore, mxCase)
