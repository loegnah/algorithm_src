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


N = 4
table = [
    [1, 2, 3, 4],
    [2, 3, 4, 5],
    [3, 4, 5, 6],
    [4, 5, 6, 7]
]

fwTree = [[0] * (N + 1) for _ in range(N + 1)]

for y in range(1, N + 1):
    for x in range(1, N + 1):
        fw2DUpdate(y, x, table[y - 1][x - 1])

for y in range(1, N + 1):
    print(fwTree[y][1:])
