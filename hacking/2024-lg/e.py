import sys

readline = sys.stdin.readline


def dp(cur, goalScore, usedYBin):
    global N, X, Y
    if cur == N:
        return 1 if goalScore == 0 else 0
    if goalScore < 0 or N - cur < goalScore:
        return 0
    if cache[cur][goalScore][usedYBin] != -1:
        return cache[cur][goalScore][usedYBin]

    ret = 0
    for yi in range(N):
        if usedYBin & (1 << yi):
            continue
        x, y = X[cur], Y[yi]
        nxtUsedYBin = usedYBin | (1 << yi)
        nxtGoalScore = goalScore
        if (x > 0 and y > 0) or (x < 0 and y < 0):
            nxtGoalScore -= 1 if abs(x) > abs(y) else 0
        else:
            nxtGoalScore -= 1
        ret += dp(cur + 1, nxtGoalScore, nxtUsedYBin)

    cache[cur][goalScore][usedYBin] = ret
    return ret


def findBobCards():
    global N, X
    bobCards = []
    for i in range(1, N + 1):
        if i not in X:
            bobCards.append(i)
        if -i not in X:
            bobCards.append(-i)
    return bobCards


for _ in range(int(readline())):
    N, M = map(int, readline().split())
    X = list(map(int, readline().split()))
    Y = findBobCards()
    cache = [[[-1] * (1 << 15) for _ in range(N + 1)] for _ in range(N + 1)]
    ans = dp(0, M, 0)
    print(ans)
