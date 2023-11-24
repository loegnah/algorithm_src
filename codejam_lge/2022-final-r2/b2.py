import sys
from functools import lru_cache

readline = sys.stdin.readline
sys.setrecursionlimit(100500)


def findChildren():
    ret = [[] for _ in range(n)]
    for c, p in enumerate(parents):
        if p == -1: continue
        ret[p].append(c)
    return ret


@lru_cache(maxsize=None)
def dp(cur, isSelect):
    ret = values[cur] if isSelect else 0
    if not children[cur]:
        return ret

    if isSelect:
        for c in children[cur]:
            ret += dp(c, False)
    else:
        isAllNotSelect, dfMin = True, float('inf')
        for c in children[cur]:
            cT, cF = dp(c, True), dp(c, False)
            if cT >= cF:
                ret += cT
                isAllNotSelect = False
            else:
                ret += cF
                dfMin = min(dfMin, cF - cT)
        if isAllNotSelect:
            ret -= dfMin

    return ret


for _ in range(int(readline())):
    n = int(readline())
    values = list(map(int, readline().split()))
    parents = list(map(lambda x: int(x) - 1, readline().split()))
    children = findChildren()
    root = parents.index(-1)

    print(max(dp(root, False), dp(root, True)))
    dp.cache_clear()
