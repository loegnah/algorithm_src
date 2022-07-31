import sys
from queue import Queue

readline = sys.stdin.readline
MOD = pow(10, 9) + 7


def geo_sum(a, r, n):
    if n == 0:
        return 0
    if r == 1:
        return n
    return int(a * (r ** n - 1) / (r - 1))


def sum_all(st, en):
    ret = 0
    for i in range(st + 1, en):
        ret = (ret + pow(st + 1, i - st + 1) + pow(i + 1, i - st + 1)) % MOD
    return ret


T = int(readline())
for _ in range(T):
    N = int(readline())
    A = list(map(int, readline().split()))
    visited = [False] * 300005
    qu = Queue()
    ans = 0

    for cur in range(N):
        if not visited[A[cur]]:
            visited[A[cur]] = True
            qu.put(cur)
            continue

        is_break = False
        while not qu.empty() and not is_break:
            pre = qu.get()
            visited[A[pre]] = False
            if A[pre] == A[cur]:
                is_break = True
            ans = (ans + sum_all(pre, cur)) % MOD

        visited[A[cur]] = True
        qu.put(cur)

    while not qu.empty():
        pre = qu.get()
        ans = (ans + sum_all(pre, N)) % MOD

    print(ans)
