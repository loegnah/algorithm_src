from sys import stdin
from math import ceil, floor

readline = stdin.readline

T = int(readline())
for _ in range(T):
    N, X = map(int, readline().split())

    allSum100 = 0
    for _ in range(N):
        n1, n2 = readline().split('.')
        allSum100 += int(n1 + n2)
    allSum = allSum100 / 100

    ans_mn, ans_mx = -1, -1
    for f in range(0, 10001):
        v = allSum * f
        v1, v2 = floor(v), ceil(v)
        allSumVatA = (allSum100 + v1) // 100
        allSumVatB = (allSum100 + v2) // 100
        if allSumVatA == X or allSumVatB == X:
            if ans_mn == -1:
                ans_mn = f
                ans_mx = f
            else:
                ans_mx = f
        elif ans_mx != -1:
            break
    print(ans_mn, ans_mx)
