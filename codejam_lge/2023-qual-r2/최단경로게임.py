import sys

readline = sys.stdin.readline
MAX_C = 100000007


def insertLine(x, y, c):
    global weights
    if c > weights[x][y]:
        return
    weights[x][y] = c
    weights[y][x] = c


def copyArrTwo(arrTwo):
    return [line[:] for line in arrTwo]


def makeDist(ws):
    global N
    ds = copyArrTwo(ws)
    for k in range(1, N + 1):
        for i in range(1, N + 1):
            for j in range(i + 1, N + 1):
                if ds[i][j] > ds[i][k] + ds[k][j]:
                    ds[i][j] = ds[i][k] + ds[k][j]
                    ds[j][i] = ds[i][j]
    return ds


def calcTotDist(ds):
    global N
    tot = 0
    for i in range(1, N + 1):
        for j in range(i + 1, N + 1):
            if ds[i][j] == MAX_C:
                continue
            tot += ds[i][j]
    return tot


def makeNewDist(origin_ds, a, b, w):
    ds = copyArrTwo(origin_ds)
    for i in range(1, N + 1):
        for j in range(i + 1, N + 1):
            d1 = ds[i][a] + w + ds[b][j]
            d2 = ds[i][b] + w + ds[a][j]
            ds[i][j] = min(ds[i][j], d1, d2)
            ds[j][i] = ds[i][j]
    return ds


for _ in range(int(readline())):
    N, M, Q = map(int, readline().split())

    distTotalList = []
    weights = [[MAX_C] * (N + 1) for _ in range(N + 1)]

    for _ in range(M):
        xi, yi, ci = map(int, readline().split())
        insertLine(xi, yi, ci)
    for ii in range(1, N + 1):
        weights[ii][ii] = 0

    dists = makeDist(weights)
    totDist = calcTotDist(dists)
    distTotalList.append((totDist, dists))
    ans = []

    for _ in range(Q):
        ipt = list(map(int, readline().split()))
        if ipt[0] == 1:
            ans.append(distTotalList[-1][0])
        elif ipt[0] == 2:
            preTotDist, preDists = distTotalList[-1]
            newDists = makeNewDist(preDists, ipt[1], ipt[2], ipt[3])
            newTotDist = calcTotDist(newDists)
            distTotalList.append((newTotDist, newDists))
        elif ipt[0] == 3:
            if len(distTotalList) > 1:
                distTotalList.pop()

    print(' '.join(map(str, ans)))
