import sys

readline = sys.stdin.readline


def calc(ab, da, db):
    return ab[0] + da, (ab[1] - db)


def makeCase(cur: int):
    global X, M, cache
    if cur == M:
        return [(0, 0)]
    if cur == M - 1:
        return [(int(X[cur]), 0)]
    if cache[cur]:
        return cache[cur]
    ret = []
    for nxt in range(cur + 1, M + 1):
        cases = makeCase(nxt)
        num = int(X[cur:nxt])
        k = int(M - 1 - nxt)
        plusLoc = 1 << k if k >= 0 else 0
        ret.extend(list(map(lambda x: calc(x, num, plusLoc), cases)))
    cache[cur] = ret
    return ret


for _ in range(int(readline())):
    N, X = readline().split()
    V = list(map(int, readline().split()))
    M = len(X)
    cache = [None] * M
    P = sorted(makeCase(0))

    Vs, Vp = 0, 0
    bit = (1 << 16) - 1
    for vi in V:
        Vs += P[vi - 1][0]
        Vp += bin(-P[vi - 1][1]).count("1")
    print(Vs, Vp)
