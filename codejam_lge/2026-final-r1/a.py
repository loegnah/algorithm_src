import heapq
import sys

readline = sys.stdin.readline


def main():
    N, M, K = map(int, readline().split())
    T = list(map(int, readline().split()))
    S = [x - 1 for x in map(int, readline().split())]

    adj = [[] for _ in range(N)]
    for _ in range(M):
        a, b, w = map(int, readline().split())
        a -= 1; b -= 1
        adj[a].append((b, w))
        adj[b].append((a, w))

    # 다중 소스 Dijkstra: 각 구역의 원래 진압 시간 계산
    # original[v] = min over all u of (T[u] + dist(u, v))
    INF = float('inf')
    original = list(T)
    heap = [(T[u], u) for u in range(N)]
    heapq.heapify(heap)

    while heap:
        d, u = heapq.heappop(heap)
        if d > original[u]:
            continue
        for v, w in adj[u]:
            nd = d + w
            if nd < original[v]:
                original[v] = nd
                heapq.heappush(heap, (nd, v))

    # 각 후보 구역에 대해 보수 후 전체 진압 시간 계산
    min_total = INF
    max_total = 0

    for s in S:
        # 후보 s에서 단일 소스 Dijkstra
        dist_s = [INF] * N
        dist_s[s] = 0
        heap = [(0, s)]
        while heap:
            d, u = heapq.heappop(heap)
            if d > dist_s[u]:
                continue
            for v, w in adj[u]:
                nd = d + w
                if nd < dist_s[v]:
                    dist_s[v] = nd
                    heapq.heappush(heap, (nd, v))

        new_T_s = T[s] // 2
        total = 0
        for v in range(N):
            val = new_T_s + dist_s[v]
            if val > original[v]:
                val = original[v]
            if val > total:
                total = val

        if total < min_total:
            min_total = total
        if total > max_total:
            max_total = total

    print(min_total, max_total)


main()
