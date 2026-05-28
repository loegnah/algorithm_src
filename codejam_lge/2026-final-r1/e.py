import sys
sys.setrecursionlimit(100000)

readline = sys.stdin.readline


def solve(N, M, C, grid):
    clean = [[grid[i][j] == '.' for j in range(M)] for i in range(N)]

    psum = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            psum[i + 1][j + 1] = psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + int(clean[i][j])

    INF = float('inf')

    clean_flat = [False] * (N * M)
    for i in range(N):
        for j in range(M):
            clean_flat[i * M + j] = clean[i][j]

    cell_row = [0] * (N * M)
    cell_col = [0] * (N * M)
    for i in range(N):
        for j in range(M):
            idx = i * M + j
            cell_row[idx] = i
            cell_col[idx] = j

    probe_order = {}
    for x1 in range(N):
        for x2 in range(x1, N):
            for y1 in range(M):
                for y2 in range(y1, M):
                    probes = []
                    for x in range(x1, x2 + 1):
                        xM = x * M
                        for y in range(y1, y2 + 1):
                            probes.append((C[x][y], xM + y, x, y))
                    probes.sort()
                    probe_order[(x1, y1, x2, y2)] = probes

    cache = {}
    cr = cell_row
    cc = cell_col
    cf = clean_flat

    def dp(x1, y1, x2, y2, excluded):
        key = (x1, y1, x2, y2, excluded)
        r = cache.get(key)
        if r is not None:
            return r

        nc = (psum[x2 + 1][y2 + 1] - psum[x1][y2 + 1]
              - psum[x2 + 1][y1] + psum[x1][y1])
        nt = (x2 - x1 + 1) * (y2 - y1 + 1)

        nex = len(excluded)
        if nex:
            ec = 0
            for e in excluded:
                ec += cf[e]
            nc -= ec
            nt -= nex

        nd = nt - nc
        if nc + (1 if nd > 0 else 0) <= 1:
            cache[key] = 0
            return 0

        ex_set = set(excluded)
        best = INF

        for cost, e_xy, x, y in probe_order[(x1, y1, x2, y2)]:
            if cost >= best:
                break
            if e_xy in ex_set:
                continue

            worst = 0

            # Q1: [x..x2]*[y..y2]
            if nex == 0:
                sub1 = (e_xy,)
            else:
                s = [e_xy]
                for e in excluded:
                    if cr[e] >= x and cr[e] <= x2 and cc[e] >= y and cc[e] <= y2:
                        s.append(e)
                s.sort()
                sub1 = tuple(s)
            v = dp(x, y, x2, y2, sub1)
            if v > worst:
                worst = v
                if cost + worst >= best:
                    continue

            # Q2: [x..x2]*[y1..y]
            if nex == 0:
                sub2 = (e_xy,)
            else:
                s = [e_xy]
                for e in excluded:
                    if cr[e] >= x and cr[e] <= x2 and cc[e] >= y1 and cc[e] <= y:
                        s.append(e)
                s.sort()
                sub2 = tuple(s)
            v = dp(x, y1, x2, y, sub2)
            if v > worst:
                worst = v
                if cost + worst >= best:
                    continue

            # Q3: [x1..x]*[y..y2]
            if nex == 0:
                sub3 = (e_xy,)
            else:
                s = [e_xy]
                for e in excluded:
                    if cr[e] >= x1 and cr[e] <= x and cc[e] >= y and cc[e] <= y2:
                        s.append(e)
                s.sort()
                sub3 = tuple(s)
            v = dp(x1, y, x, y2, sub3)
            if v > worst:
                worst = v
                if cost + worst >= best:
                    continue

            # Q4: [x1..x]*[y1..y]
            if nex == 0:
                sub4 = (e_xy,)
            else:
                s = [e_xy]
                for e in excluded:
                    if cr[e] >= x1 and cr[e] <= x and cc[e] >= y1 and cc[e] <= y:
                        s.append(e)
                s.sort()
                sub4 = tuple(s)
            v = dp(x1, y1, x, y, sub4)
            if v > worst:
                worst = v
                if cost + worst >= best:
                    continue

            best = cost + worst

        cache[key] = best
        return best

    return dp(0, 0, N - 1, M - 1, ())


if __name__ == "__main__":
    N, M = map(int, readline().split())
    C = []
    for _ in range(N):
        C.append(list(map(int, readline().split())))
    grid = []
    for _ in range(N):
        grid.append(readline().strip())
    print(solve(N, M, C, grid))
