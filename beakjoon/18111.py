from sys import stdin

readline = stdin.readline

MaxHeight = 256
blocks = [0 for _ in range(MaxHeight + 1)]
N, M, B = map(int, readline().split())

for _ in range(N):
    for h in map(int, readline().split()):
        blocks[h] += 1

ans = (float('inf'), 0)
for i in range(MaxHeight + 1):
    t, b = 0, B
    for h, cnt in enumerate(blocks):
        if h < i:
            t += cnt * (i - h)
            b -= cnt * (i - h)
        else:
            t += cnt * (h - i) * 2
            b += cnt * (h - i)
    if b >= 0 and t <= ans[0]:
        ans = (t, i)

print(' '.join(map(str, ans)))
