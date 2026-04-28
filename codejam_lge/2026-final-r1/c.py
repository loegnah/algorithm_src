import sys
from collections import deque

readline = sys.stdin.readline

def bfs(adj, root, N):
    parent = [-1] * N
    order = []
    visited = [False] * N
    queue = deque([root])
    visited[root] = True
    while queue:
        v = queue.popleft()
        order.append(v)
        for u in adj[v]:
            if not visited[u]:
                visited[u] = True
                parent[u] = v
                queue.append(u)
    return parent, order


def solve(N, adj):
    if N <= 2:
        return N

    parent, order = bfs(adj, 0, N)

    dp_up = [1] * N
    dp_dn = [1] * N

    for v in reversed(order):
        for u in adj[v]:
            if parent[u] != v:
                continue
            if u > v:
                dp_up[v] = max(dp_up[v], 1 + dp_dn[u])
            else:
                dp_dn[v] = max(dp_dn[v], 1 + dp_up[u])

    ans = 0
    for v in range(N):
        ans = max(ans, dp_up[v], dp_dn[v])

    return ans


if __name__ == "__main__":
    N = int(readline())
    adj = [[] for _ in range(N)]
    for _ in range(N - 1):
        u, v = map(int, readline().split())
        adj[u].append(v)
        adj[v].append(u)
    print(solve(N, adj))
