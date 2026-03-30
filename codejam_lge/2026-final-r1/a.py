import heapq
import sys

readline = sys.stdin.readline

INF = float('inf')


def dijkstra(adj, N, sources):
    dist = [INF] * N
    heap = []
    for u, d in sources:
        dist[u] = d
        heap.append((d, u))
    heapq.heapify(heap)

    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                heapq.heappush(heap, (nd, v))

    return dist


def solve(N, M, K, T, S, adj):
    origin = dijkstra(adj, N, [(u, T[u]) for u in range(N)])

    min_total = INF
    max_total = 0

    for s in S:
        dist_s = dijkstra(adj, N, [(s, 0)])

        new_T_s = T[s] // 2
        total = 0
        for v in range(N):
            val = new_T_s + dist_s[v]
            if val > origin[v]:
                val = origin[v]
            if val > total:
                total = val

        if total < min_total:
            min_total = total
        if total > max_total:
            max_total = total

    return min_total, max_total


if __name__ == "__main__":
    N, M, K = map(int, readline().split())
    T = list(map(int, readline().split()))
    S = [s - 1 for s in map(int, readline().split())]

    adj = [[] for _ in range(N)]
    for _ in range(M):
        a, b, w = map(int, readline().split())
        a -= 1
        b -= 1
        adj[a].append((b, w))
        adj[b].append((a, w))

    print(*solve(N, M, K, T, S, adj))
