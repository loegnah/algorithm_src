import sys

readline = sys.stdin.readline

T = int(readline())
for _ in range(T):
    N, M, K = map(int, readline().split())
    h = list(map(int, readline().split()))
    values = list(map(int, readline().split()))
    top = []
    preSum = 0
    for hi in h:
        top.append(values[preSum:preSum + hi])
        preSum += hi

    dp = [[0 for _ in range(K + 1)] for _ in range(2)]

    for i in range(1, M + 1):
        cur, pre = i % 2, (i - 1) % 2
        dp[cur] = [0] * (K + 1)
        for j in range(1, K + 1):
            subSum = 0
            for h in range(len(top[i - 1]) + 1):
                if h > j:
                    break
                subSum += 0 if h == 0 else top[i - 1][h - 1]
                dp[cur][j] = max(dp[cur][j], subSum + dp[pre][j - h])

    print(dp[M % 2][K])
