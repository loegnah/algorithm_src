import sys
from collections import deque

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


def subtree_dp(adj, parent, order, N):
    dp_up = [1] * N
    dp_dn = [1] * N
    top_up = [[] for _ in range(N)]
    top_dn = [[] for _ in range(N)]

    for v in reversed(order):
        up_vals = []
        dn_vals = []
        for u in adj[v]:
            if parent[u] != v:
                continue
            if u > v:
                val = 1 + dp_dn[u]
                if val > dp_up[v]:
                    dp_up[v] = val
                up_vals.append((val, u))
            else:
                val = 1 + dp_up[u]
                if val > dp_dn[v]:
                    dp_dn[v] = val
                dn_vals.append((val, u))
        up_vals.sort(reverse=True)
        top_up[v] = up_vals[:2]
        dn_vals.sort(reverse=True)
        top_dn[v] = dn_vals[:2]

    return dp_up, dp_dn, top_up, top_dn


def best_excluding(top, from_parent, c):
    best = 1
    if top:
        if top[0][1] != c:
            best = top[0][0]
        elif len(top) >= 2:
            best = top[1][0]
    if from_parent > best:
        best = from_parent
    return best


def reroot(adj, parent, order, dp_up, dp_dn, top_up, top_dn):
    root = order[0]
    from_parent_up = [0] * len(order)
    from_parent_dn = [0] * len(order)

    ans = max(dp_up[root], dp_dn[root])
    if len(top_up[root]) >= 2:
        ans = max(ans, top_up[root][0][0] + top_up[root][1][0] - 1)
    if len(top_dn[root]) >= 2:
        ans = max(ans, top_dn[root][0][0] + top_dn[root][1][0] - 1)

    for v in order:
        for c in adj[v]:
            if parent[c] != v:
                continue

            best_up_excl = best_excluding(top_up[v], from_parent_up[v], c)
            best_dn_excl = best_excluding(top_dn[v], from_parent_dn[v], c)

            if v > c:
                from_parent_up[c] = 1 + best_dn_excl
            else:
                from_parent_dn[c] = 1 + best_up_excl

            cur = max(
                max(dp_up[c], from_parent_up[c]),
                max(dp_dn[c], from_parent_dn[c]),
            )
            if cur > ans:
                ans = cur

            for direction in ("up", "dn"):
                top = top_up[c] if direction == "up" else top_dn[c]
                fp = from_parent_up[c] if direction == "up" else from_parent_dn[c]
                cands = [val for val, _ in top[:2]]
                if fp > 0:
                    cands.append(fp)
                    cands.sort(reverse=True)
                if len(cands) >= 2:
                    combined = cands[0] + cands[1] - 1
                    if combined > ans:
                        ans = combined

    return ans


def solve(N, adj):
    if N <= 2:
        return N

    parent, order = bfs(adj, 0, N)
    dp_up, dp_dn, top_up, top_dn = subtree_dp(adj, parent, order, N)
    return reroot(adj, parent, order, dp_up, dp_dn, top_up, top_dn)


if __name__ == "__main__":
    readline = sys.stdin.readline
    N = int(readline())
    adj = [[] for _ in range(N)]
    for _ in range(N - 1):
        u, v = map(int, readline().split())
        adj[u].append(v)
        adj[v].append(u)
    print(solve(N, adj))
