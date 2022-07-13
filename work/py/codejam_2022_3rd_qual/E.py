import sys

readline = sys.stdin.readline
MX = pow(10, 9) + 7


def calc(i, j):
    vi, vj = nums[i], nums[j]
    ret = (A * (vi ^ vj) + B * (vi & vj) + C * (vi | vj)) % MOD
    return ret
    # return (A * (vi ^ vj) + B * (vi & vj) + C * (vi | vj)) % MOD


def dp(st, en):
    if st == en:
        return 0
    # if st == en - 1:
    #     return calc(st, en)

    ret = MX
    for k in range(st, en):
        ret = min(ret, calc(k, k + 1) + dp(st, k) + dp(k + 1, en))
    print(ret)
    return ret


for _ in range(int(readline())):
    n = int(readline())
    A, B, C, MOD = map(int, readline().split())
    nums = list(map(int, readline().split()))

    print(dp(0, n - 1))
