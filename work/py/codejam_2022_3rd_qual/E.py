import sys

readline = sys.stdin.readline
MX = float('inf')
subSums = [[0] * 2005 for _ in range(2005)]
rangePenalty = [[0] * 2005 for _ in range(2005)]


def calc(i, j):
    vi, vj = nums[i], nums[j]
    return (A * (vi ^ vj) + B * (vi & vj) + C * (vi | vj)) % MOD


def dp(st, en):
    if cache[st][en] != -1:
        return cache[st][en]
    ret = 0
    if st == en:
        ret = 0
    elif st == en - 1:
        ret = rangePenalty[st][en]
    else:
        mn = float('inf')
        for k in range(st, en):
            mn = min(mn, dp(st, k) + dp(k + 1, en))
        ret = mn + rangePenalty[st][en]
    cache[st][en] = ret
    return ret


for _ in range(int(readline())):
    n = int(readline())
    A, B, C, MOD = map(int, readline().split())
    nums = list(map(int, readline().split()))
    cache = [[-1] * n for _ in range(n + 1)]

    if n == 1:
        print(0)
        continue

    for p in range(n):
        subSums[p][p] = 0
        for q in range(p + 1, n):
            subSums[p][q] = subSums[p][q - 1] + calc(p, q)

    for q in range(n - 1, -1, -1):
        rangePenalty[q][q] = subSums[q][q]
        for p in range(q - 1, -1, -1):
            rangePenalty[p][q] = rangePenalty[p + 1][q] + subSums[p][q]

    print(dp(0, n - 1))
