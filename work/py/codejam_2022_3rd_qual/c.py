import sys
from functools import lru_cache

readline = sys.stdin.readline
MOD = pow(10, 9) + 7


@lru_cache(maxsize=None)
def dp(start_y, start_x, cut):
    global Y, X, N, toppings, wantToppings
    if start_y == Y or start_x == X:
        return 0

    want = wantToppings[cut]
    ret = 0
    ly, lx = Y, X

    for y in range(start_y, Y):
        for x in range(start_x, lx):
            if toppings[y][x] != want:
                continue
            if cut == N - 1:
                return 1
            for ny in range(y + 1, ly):
                ret = (ret + dp(ny, start_x, cut + 1)) % MOD
            for nx in range(x + 1, lx):
                ret = (ret + dp(start_y, nx, cut + 1)) % MOD
            ly, lx = y, x
    return ret


T = int(readline())
for _ in range(T):
    Y, X, N = map(int, readline().split())
    toppings = [readline().strip()]
    for i in range(1, Y):
        toppings.append(readline().strip())
    wantToppings = readline().strip()

    print(dp(0, 0, 0))
    dp.cache_clear()
