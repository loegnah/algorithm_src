import sys
from operator import mul

MOD = 987654321


def solve(N, M, V, adj):
    children = [[] for _ in range(N + 1)]
    visited = [False] * (N + 1)
    queue = [1]
    visited[1] = True
    bfs_order = []
    head = 0
    while head < len(queue):
        u = queue[head]
        head += 1
        bfs_order.append(u)
        for nb in adj[u]:
            if not visited[nb]:
                visited[nb] = True
                children[u].append(nb)
                queue.append(nb)

    size = [1] * (N + 1)
    P_total = [0] * (N + 1)
    zero_vec = [0] * M
    pair = [zero_vec] * (N + 1)
    A = [zero_vec] * (N + 1)
    B = [zero_vec] * (N + 1)

    for u in reversed(bfs_order):
        ch = children[u]
        lc = len(ch)
        if lc == 1:
            c = ch[0]
            size[u] = 1 + size[c]
            P_total[u] = P_total[c]
            pair[u] = pair[c]
            A[u] = A[c]
            B[u] = B[c]
        elif lc == 2:
            d1, d2 = ch
            s1 = size[d1]
            s2 = size[d2]
            size[u] = 1 + s1 + s2
            v_color = V[u] - 1
            p1 = pair[d1]
            p2 = pair[d2]
            new_pair = [(a + b) % MOD for a, b in zip(p1, p2)]
            new_pair[v_color] = (new_pair[v_color] + s1 * s2) % MOD
            pair[u] = new_pair
            P_total[u] = (P_total[d1] + P_total[d2] + s1 * s2) % MOD
            tri_vc = (s1 * p2[v_color] + s2 * p1[v_color]) % MOD
            tt = (s1 * P_total[d2] + s2 * P_total[d1]) % MOD
            a1 = A[d1]
            a2 = A[d2]
            new_A = [(a + b) % MOD for a, b in zip(a1, a2)]
            new_A[v_color] = (new_A[v_color] + tt) % MOD
            A[u] = new_A
            b1 = B[d1]
            b2 = B[d2]
            new_B = [(a + b) % MOD for a, b in zip(b1, b2)]
            new_B[v_color] = (new_B[v_color] + tri_vc) % MOD
            B[u] = new_B

    answer = 0
    for u in range(1, N + 1):
        if len(children[u]) != 2:
            continue
        c1, c2 = children[u]
        c_L = V[u] - 1
        p1 = pair[c1]
        p2 = pair[c2]
        caseA_1 = P_total[c1] * P_total[c2] % MOD
        caseA_2 = sum(map(mul, p1, p2)) % MOD
        caseA = (8 * caseA_1 + 16 * caseA_2) % MOD
        caseB_1 = (size[c1] * A[c2][c_L] + size[c2] * A[c1][c_L]) % MOD
        caseB_2 = (size[c1] * B[c2][c_L] + size[c2] * B[c1][c_L]) % MOD
        caseB = (8 * caseB_1 + 16 * caseB_2) % MOD
        answer = (answer + caseA + caseB) % MOD

    return answer


if __name__ == "__main__":
    readline = sys.stdin.readline
    N, M = map(int, readline().split())
    V = [0] + list(map(int, readline().split()))
    adj = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
        u, v = map(int, readline().split())
        adj[u].append(v)
        adj[v].append(u)
    print(solve(N, M, V, adj))
