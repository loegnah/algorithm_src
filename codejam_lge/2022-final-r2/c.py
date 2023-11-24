from sys import stdin
from collections import defaultdict

readline = stdin.readline


def make_cnt_idx_pair(arr):
    return sorted([(cnt, i) for i, cnt in enumerate(arr) if cnt != 0], reverse=True)


def calc_sum(pairs, ln, cnt_value):
    ret = 0
    for cnt, i in pairs:
        ret += ln * cnt
        cnt_value[cnt] = ln  # cnt --- min value
        ln -= 1
    return ret


for _ in range(int(readline())):
    n, m, k = map(int, readline().split())
    x_cnt, y_cnt = [0] * (n + 1), [0] * (m + 1)
    e = []

    for _ in range(k):
        x, y = map(int, readline().split())
        e.append((x, y))
        x_cnt[x] += 1
        y_cnt[y] += 1

    x_pair, y_pair = make_cnt_idx_pair(x_cnt), make_cnt_idx_pair(y_cnt)
    x_cnt_value, y_cnt_value = defaultdict(int), defaultdict(int)

    S_H = calc_sum(x_pair, n, x_cnt_value) + calc_sum(y_pair, m, y_cnt_value)

    min_sum_value = float('inf')
    xy = (-1, -1)
    for ix, iy in e:
        sum_value = x_cnt_value[x_cnt[ix]] + y_cnt_value[y_cnt[iy]]
        if sum_value < min_sum_value:
            min_sum_value = sum_value
            xy = (ix, iy)

    S_H2 = S_H - x_cnt_value[x_cnt[xy[0]]] - y_cnt_value[y_cnt[xy[1]]]

    print(S_H, S_H2)
