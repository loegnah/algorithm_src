import sys


def calc(k):
    ret = k
    while k:
        ret += k % 10
        k //= 10
    return ret


nStr = sys.stdin.readline()
N, nLen = int(nStr), len(nStr)
ans = 0

for i in range(max(N - nLen * 10, 1), N):
    if calc(i) == N:
        ans = i
        break
print(ans)
