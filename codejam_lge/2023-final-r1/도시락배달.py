import sys
from itertools import combinations

readline = sys.stdin.readline
MX = 987654321


def calcEsDist(spotA, spotB):
    global escalator
    _, ax, ay = spotA
    _, bx, by = spotB
    min_dist = MX
    for (ex, ey) in escalator:
        min_dist = min(min_dist, abs(ex - ax) + abs(ey - ay) + abs(ex - bx) + abs(ey - by))
    return min_dist


def calcDist(spotA, spotB):
    az, ax, ay = spotA
    bz, bx, by = spotB
    dz = abs(az - bz) if az >= bz else (abs(az - bz) * 2)
    dxy = calcEsDist(spotA, spotB) if az != bz else (abs(ax - bx) + abs(ay - by))
    return


T = int(readline())
for _ in range(T):
    F, W, L, N = map(int, readline().split())
    spot = [list(map(int, readline().split()))]
    escalator = [(1, 1), (W, 1), (1, L), (W, L)]
    for _ in range(N):
        spot.append(list(map(int, readline().split())))

    allVisited = (1 << (N + 1)) - 1
    dp = [[MX] * N for _ in range(allVisited + 1)]
    dp[1][0] = 0

    for subset_size in range(2, N + 2):
        subsets = combinations(range(1, N), subset_size - 1)
        for subset in subsets:
            subset = (0,) + subset
            print(subset)
            subset_bits = sum(1 << i for i in subset)
            for last_node in subset:
                if last_node == 0:  # 시작 정점은 건너뜀
                    continue
                for prev_node in subset:
                    if prev_node == last_node:  # 이전 정점이 자기 자신인 경우 건너뜀
                        continue
                    if dp[subset_bits ^ (1 << last_node)][prev_node] == MX:  # 이전 부분 집합이 방문되지 않은 경우 건너뜀
                        continue
                    dp[subset_bits][last_node] = min(dp[subset_bits][last_node],
                                                     dp[subset_bits ^ (1 << last_node)][prev_node] + calcDist(
                                                         spot[prev_node], spot[last_node]))
                    # ans = MX

    # for st in range(N):
    #     k = calcDist(store, spot[st])
    #     ans = min(ans, calcDist(store, spot[st]) + dp(st, 1 << st))
    # print(ans)
