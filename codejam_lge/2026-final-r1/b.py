import sys

readline = sys.stdin.readline


def main():
    N, K = map(int, readline().split())
    A = list(map(int, readline().split()))

    if N < 2 * K:
        print(-1)
        return

    # Sparse Table for Range Maximum Query
    LOG = [0] * (N + 1)
    for i in range(2, N + 1):
        LOG[i] = LOG[i // 2] + 1

    maxlog = LOG[N] + 1
    sparse = [A[:]]
    for j in range(1, maxlog):
        prev = sparse[j - 1]
        half = 1 << (j - 1)
        length = N - (1 << j) + 1
        curr = [0] * length
        for i in range(length):
            curr[i] = prev[i] if prev[i] > prev[i + half] else prev[i + half]
        sparse.append(curr)

    def query(l, r):
        k = LOG[r - l + 1]
        a, b = sparse[k][l], sparse[k][r - (1 << k) + 1]
        return a if a > b else b

    # 거리 K, K+1 간선만 생성 (이것으로 MST 구성 가능)
    edges = []
    for i in range(N - K):
        edges.append((query(i, i + K), i, i + K))
    for i in range(N - K - 1):
        edges.append((query(i, i + K + 1), i, i + K + 1))

    # Kruskal's MST
    edges.sort()

    parent = list(range(N))
    rnk = [0] * N

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(x, y):
        px, py = find(x), find(y)
        if px == py:
            return False
        if rnk[px] < rnk[py]:
            px, py = py, px
        parent[py] = px
        if rnk[px] == rnk[py]:
            rnk[px] += 1
        return True

    total = 0
    count = 0
    for cost, u, v in edges:
        if union(u, v):
            total += cost
            count += 1
            if count == N - 1:
                break

    print(total if count == N - 1 else -1)


main()
