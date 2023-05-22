from sys import stdin

readline = stdin.readline
MX = 10 ** 14

for _ in range(int(readline())):
    N, K, a, b = map(int, readline().split())
    S = list(map(int, readline().split()))

    tot = [[MX] * (K + 1) for _ in range(2)]
    tot[1][0] = 0
    for i in range(N):
        cur, pre = i % 2, (i + 1) % 2
        cost = a * ((S[i] - 1) ** 2) + b if S[i] > 1 else 0

        for rmn in range(K + 1):
            if rmn - S[i] < 0:
                tot[cur][rmn] = min(tot[pre][rmn], cost)
            else:
                tot[cur][rmn] = min(tot[pre][rmn], cost + tot[pre][rmn - S[i]])

    print(tot[(N - 1) % 2][K])
