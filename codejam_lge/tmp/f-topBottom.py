import sys
from functools import lru_cache

readline = sys.stdin.readline
sys.setrecursionlimit(2500)

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


    @lru_cache(maxsize=None)
    def my_dp(m, k):
        if m == M:
            return 0 if k == 0 else float("-inf")
        ret = my_dp(m + 1, k)
        sub_sum = 0
        for i in range(min(k, len(top[m]))):
            sub_sum += top[m][i]
            ret = max(ret, sub_sum + my_dp(m + 1, k - i - 1))
        return ret


    print(my_dp(0, K))
