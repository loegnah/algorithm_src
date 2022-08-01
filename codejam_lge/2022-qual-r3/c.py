import sys

readline = sys.stdin.readline
MOD = pow(10, 9) + 7


def dp(start_y, start_x, cut):
    if start_y == Y or start_x == X:
        return 0
    if cache[start_y][start_x][cut] != -1:
        return cache[start_y][start_x][cut]

    want = wantToppings[cut]
    y_want = sbr[want][0][start_y][start_x]
    x_want = sbr[want][1][start_y][start_x]
    ret = 0

    if cut == N - 1 and (y_want != Y or x_want != X):
        return 1

    if y_want != Y:
        for cut_y in range(y_want + 1, Y):
            ret = (ret + dp(cut_y, start_x, cut + 1)) % MOD
    if x_want != X:
        for cut_x in range(x_want + 1, X):
            ret = (ret + dp(start_y, cut_x, cut + 1)) % MOD

    cache[start_y][start_x][cut] = ret
    return ret


def calc_sbr():
    for x in range(X - 1, -1, -1):
        for y in range(Y - 1, -1, -1):
            for s in sbrList:
                if s == toppings[y][x]:
                    sbr[s][0][y][x] = y
                else:
                    sbr[s][0][y][x] = min(sbr[s][0][y + 1][x], sbr[s][0][y][x + 1])

    for y in range(Y - 1, -1, -1):
        for x in range(X - 1, -1, -1):
            for s in sbrList:
                if s == toppings[y][x]:
                    sbr[s][1][y][x] = x
                else:
                    sbr[s][1][y][x] = min(sbr[s][1][y + 1][x], sbr[s][1][y][x + 1])


T = int(readline())
for _ in range(T):
    Y, X, N = map(int, readline().split())
    toppings = [readline().strip()]
    for i in range(1, Y):
        toppings.append(readline().strip())
    wantToppings = readline().strip()
    cache = [[[-1] * N for _ in range(X)] for _ in range(Y)]

    sbrList = ['S', 'B', 'R']
    sbr = {
        'S': [[[Y for _ in range(X + 1)] for _ in range(Y + 1)], [[X for _ in range(X + 1)] for _ in range(Y + 1)]],
        'B': [[[Y for _ in range(X + 1)] for _ in range(Y + 1)], [[X for _ in range(X + 1)] for _ in range(Y + 1)]],
        'R': [[[Y for _ in range(X + 1)] for _ in range(Y + 1)], [[X for _ in range(X + 1)] for _ in range(Y + 1)]],
    }

    calc_sbr()
    print(dp(0, 0, 0))
