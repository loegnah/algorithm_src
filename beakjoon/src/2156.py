import sys

sys.setrecursionlimit(15000)
readline = sys.stdin.readline


def findMaxWineAmt(idx):
    if idx >= n:
        return 0
    if cache[idx] != -1:
        return cache[idx]

    ret = max(findMaxWineAmt(idx + 1), wineAmt[idx] + findMaxWineAmt(idx + +2))
    if idx <= n - 2:
        ret = max(ret, wineAmt[idx] + wineAmt[idx + 1] + findMaxWineAmt(idx + 3))
    cache[idx] = ret
    return ret


wineAmt = []
n = int(readline())
for _ in range(n):
    wineAmt.append(int(readline()))
cache = [-1] * n
print(findMaxWineAmt(0))
