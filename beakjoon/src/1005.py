import sys

sys.setrecursionlimit(10 ** 6)
readline = sys.stdin.readline


def findMaxTime(num):
    if cache[num] != -1:
        return cache[num]

    maxDeps = 0
    for dep in depends[num]:
        maxDeps = max(maxDeps, findMaxTime(dep))
    cache[num] = maxDeps + delays[num - 1]
    return cache[num]


for _ in range(int(readline())):
    N, K = map(int, readline().split())
    delays = list(map(int, readline().split()))
    depends = [[] for _ in range(N + 1)]
    for _ in range(K):
        x, y = map(int, readline().split())
        depends[y].append(x)
    goal = int(readline())

    cache = [-1] * (N + 1)
    print(findMaxTime(goal))
