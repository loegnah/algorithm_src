import sys

readline = sys.stdin.readline


def query(sparse, store, l, r):
    k = store[r - l + 1]
    a, b = sparse[k][l], sparse[k][r - (1 << k) + 1]
    return a if a > b else b


def find(parent, x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x


def union(parent, rnk, x, y):
    px, py = find(parent, x), find(parent, y)
    if px == py:
        return False
    if rnk[px] < rnk[py]:
        px, py = py, px
    parent[py] = px
    if rnk[px] == rnk[py]:
        rnk[px] += 1
    return True


def solve(N, K, A):
    if N < 2 * K:
        return -1

    store = [0] * (N + 1)
    for n in range(2, N + 1):
        store[n] = store[n // 2] + 1

    maxlog = store[N] + 1
    sparse = [A[:]]
    for j in range(1, maxlog):
        prev = sparse[j - 1]
        half = 1 << (j - 1)
        length = N - (1 << j) + 1
        curr = [0] * length
        for i in range(length):
            curr[i] = prev[i] if prev[i] > prev[i + half] else prev[i + half]
        sparse.append(curr)

    edges = []
    for i in range(N - K):
        edges.append((query(sparse, store, i, i + K), i, i + K))
    for i in range(N - K - 1):
        edges.append((query(sparse, store, i, i + K + 1), i, i + K + 1))

    edges.sort()

    parent = list(range(N))
    rnk = [0] * N

    total = 0
    count = 0
    for cost, u, v in edges:
        if union(parent, rnk, u, v):
            total += cost
            count += 1
            if count == N - 1:
                break

    return total if count == N - 1 else -1


if __name__ == "__main__":
    N, K = map(int, readline().split())
    A = list(map(int, readline().split()))
    print(solve(N, K, A))
