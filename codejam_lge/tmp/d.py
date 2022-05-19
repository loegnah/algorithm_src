import sys
from collections import deque

readline = sys.stdin.readline
MOD = pow(10, 9) + 7


def geo_sum(a, r, n):
    if n == 0:
        return 0
    if r == 1:
        return n
    return (((a * pow(r, n, MOD)) % MOD - a) % MOD * (pow(r - 1, MOD - 2, MOD))) % MOD


def sum_all(p, ln):
    return geo_sum(pow(p, 2, MOD), p, ln)


T = int(readline())
for _ in range(T):
    N = int(readline())
    A = list(map(int, readline().split()))
    visited = [False] * 300005
    qu = deque()
    ans = 0
    start = 0

    for cur in range(1, N + 1):
        a_cur = A[cur - 1]
        if not visited[a_cur]:
            ans = (ans + sum_all(cur, cur - start - 1)) % MOD
            visited[a_cur] = True
            qu.append(cur)
            continue

        while qu:
            idx = qu.popleft()
            visited[A[idx - 1]] = False
            ans = (ans + sum_all(idx, cur - idx - 1)) % MOD
            if A[idx - 1] == a_cur:
                start = idx
                break
        ans = (ans + sum_all(cur, cur - start - 1)) % MOD
        visited[a_cur] = True
        qu.append(cur)

    while qu:
        idx = qu.popleft()
        ans = (ans + sum_all(idx, N - idx)) % MOD
    print(int(ans))
