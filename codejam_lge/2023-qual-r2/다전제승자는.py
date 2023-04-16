import sys

readline = sys.stdin.readline
MOD = (10 ** 9) + 7
MX = (10 ** 5) * 2 + 1

k = 1
fac = [1]
for i in range(1, MX + 1):
    k = (k * i) % MOD
    fac.append(k)


def pw(x, y):
    if y == 0:
        return 1
    if y % 2:
        return (x * pw(x, y - 1)) % MOD
    ret = pw(x, y // 2)
    return (ret * ret) % MOD


fac_inv = [0] * (MX + 1)
fac_inv[MX] = pw(fac[MX], MOD - 2)
for i in range(MX - 1, -1, -1):
    fac_inv[i] = (fac_inv[i + 1] * (i + 1)) % MOD


def calcComb(x, y):
    global fac, fac_inv, MOD
    if x == y:
        return 1
    if y == 1:
        return x
    ret = (fac[x] * fac_inv[x - y]) % MOD
    ret = (ret * fac_inv[y]) % MOD
    return ret


T = int(readline())
for _ in range(T):
    N, M = map(int, readline().split())
    maxMatch = 2 * M - 1
    N2 = M - N - 1
    ans = 0

    for a in range(N):
        ans = (ans + (calcComb(N + a - 1, a) * calcComb(maxMatch - N - a, N2))) % MOD
    print(ans)
