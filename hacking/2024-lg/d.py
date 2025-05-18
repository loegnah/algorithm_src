import sys
from collections import deque

readline = sys.stdin.readline


def findParent(parent, children):
    doubleParent = False
    for i, ch in enumerate(children):
        if ch == 0:
            continue
        if parent[ch]:
            doubleParent = True
            break
        parent[ch] = i + 1

    return doubleParent


def checkAll(N, L, R):
    dq = deque()
    checked = [False] * N
    prnt = []
    for i in range(N):
        if checked[i]:
            continue
        dq.append(i)
        while dq:
            cur = dq[len(dq) - 1]
            child_l, child_r = L[cur], R[cur]
            if child_l == 0 and child_r == 0:
                dq.pop()
                continue
            if child_l:
                prnt[child_l] = cur
                dq.append(child_l)
            if child_r:
                prnt[child_r] = cur
                dq.append(child_r)
            checked[cur] = True
            dq.pop()


def solve():
    N = int(readline())
    L = list(map(int, readline().split()))
    R = list(map(int, readline().split()))

    parent = [0] * (N + 1)
    if findParent(parent, L) or findParent(parent, R):
        return 0

    roots = []
    for i in range(1, len(parent)):
        if parent[i] == 0:
            roots.append(i)

    if len(roots) != 1:
        return 0
    return 1


for t in range(int(readline())):
    print(solve())
