import sys

readline = sys.stdin.readline


def fw2DSum(ky, kx):
    cy, ret = ky, 0
    while cy > 0:
        cx = kx
        while cx > 0:
            ret += fwTree[cy][cx]
            cx -= (cx & -cx)
        cy -= (cy & -cy)
    return ret


def fw2DUpdate(ky, kx, diff):
    cy = ky
    while cy <= N:
        cx = kx
        while cx <= N:
            fwTree[cy][cx] += diff
            cx += (cx & -cx)
        cy += (cy & -cy)


N, M = map(int, readline().split())
table = [[0] * (N + 1) for _ in range(N + 1)]
fwTree = [[0] * (N + 1) for _ in range(N + 1)]

for y in range(1, N + 1):
    for x, val in enumerate(map(int, readline().split()), 1):
        table[y][x] = val
        fw2DUpdate(y, x, val)

for _ in range(M):
    cmd = list(map(int, readline().split()))
    if cmd[0] == 0:
        y, x, c = cmd[1:]
        fw2DUpdate(y, x, c - table[y][x])
        table[y][x] = c
    else:
        y1, x1, y2, x2 = cmd[1:]
        print(fw2DSum(y2, x2) + fw2DSum(y1 - 1, x1 - 1) - fw2DSum(y2, x1 - 1) - fw2DSum(y1 - 1, x2))
