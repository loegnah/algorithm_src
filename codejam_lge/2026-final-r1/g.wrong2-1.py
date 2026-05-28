import sys

MOD = 998244353

readline = sys.stdin.readline

def vec_add(a, b):
    return [(x + y) % MOD for x, y in zip(a, b)]


def make_tree(N, adj):
    children = [[] for _ in range(N + 1)]
    visited = [False] * (N + 1)
    visited[1] = True
    queue = [1]
    head = 0
    bfs_order = []
    while head < len(queue):
        u = queue[head]
        head += 1
        bfs_order.append(u)
        for nb in adj[u]:
            if not visited[nb]:
                visited[nb] = True
                children[u].append(nb)
                queue.append(nb)
    return children, bfs_order


def dp(N, M, V, children, bfs_order):
    zero = [0] * M
    size = [1] * (N + 1)
    P_total = [0] * (N + 1)
    pair = [zero] * (N + 1)
    A = [zero] * (N + 1)
    B = [zero] * (N + 1)

    for u in reversed(bfs_order):
        ch = children[u]
        if len(ch) == 1:
            c = ch[0]
            size[u] = 1 + size[c]
            P_total[u] = P_total[c]
            pair[u] = pair[c]
            A[u] = A[c]
            B[u] = B[c]
        elif len(ch) == 2:
            d1, d2 = ch
            s1, s2 = size[d1], size[d2]
            vc = V[u] - 1
            size[u] = 1 + s1 + s2
            P_total[u] = (P_total[d1] + P_total[d2] + s1 * s2) % MOD

            p = vec_add(pair[d1], pair[d2])
            p[vc] = (p[vc] + s1 * s2) % MOD
            pair[u] = p

            tt = (s1 * P_total[d1] + s2 * P_total[d2]) % MOD
            a = vec_add(A[d1], A[d2])
            a[vc] = (a[vc] + tt) % MOD
            A[u] = a

            tri = (s1 * pair[d2][vc] + s2 * pair[d1][vc]) % MOD
            b = vec_add(B[d1], B[d2])
            b[vc] = (b[vc] + tri) % MOD
            B[u] = b

    return size, P_total, pair, A, B


def solve(N, M, V, adj):
    children, bfs_order = make_tree(N, adj)
    size, P_total, pair, A, B = dp(N, M, V, children, bfs_order)

    answer = 0
    for u in range(1, N + 1):
        if len(children[u]) != 2:
            continue
        c1, c2 = children[u]
        vc = V[u] - 1

        caseA_1 = P_total[c1] * P_total[c2] % MOD
        caseA_2 = sum(map(lambda x, y: x * y, pair[c1], pair[c2])) % MOD
        caseA = (8 * caseA_1 + 16 * caseA_2) % MOD

        caseB_1 = (size[c1] * A[c2][vc] + size[c2] * A[c1][vc]) % MOD
        caseB_2 = (size[c1] * B[c2][vc] + size[c2] * B[c1][vc]) % MOD
        caseB = (16 * caseB_1 + 8 * caseB_2) % MOD

        answer = (answer + caseA + caseB) % MOD

    return answer


if __name__ == "__main__":
    N, M = map(int, readline().split())
    V = [0] + list(map(int, readline().split()))
    adj = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
        u, v = map(int, readline().split())
        adj[u].append(v)
        adj[v].append(u)
    print(solve(N, M, V, adj))
