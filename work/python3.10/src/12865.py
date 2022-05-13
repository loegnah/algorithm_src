import sys

readline = sys.stdin.readline

N, K = map(int, readline().split())
stuff = [list(map(int, readline().split())) for _ in range(N)]
dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, K + 1):
        w, v = stuff[i - 1]

        if w > j:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(v + dp[i - 1][j - w], dp[i - 1][j])

print(dp[N][K])
