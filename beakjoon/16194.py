import sys

sys.setrecursionlimit(1500)
readline = sys.stdin.readline


def dp(idx: int, card: int):
    global N, P, cache
    if idx == N:
        return 0 if card == 0 else float('inf')
    if cache[idx][card] != -1:
        return cache[idx][card]
    mn = float('inf')
    for packCnt in range(N + 1):
        cardCnt = packCnt * (idx + 1)
        if card - cardCnt < 0:
            break
        mn = min(mn, P[idx] * packCnt + dp(idx + 1, card - cardCnt))
    cache[idx][card] = mn
    return mn


N = int(readline())
P = list(map(int, readline().split()))
cache = [[-1] * (N + 5) for _ in range(N + 5)]
print(dp(0, N))
