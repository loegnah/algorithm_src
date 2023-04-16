# 2차원 종이 놀이
import sys
from bisect import bisect_left, bisect_right, insort

readline = sys.stdin.readline

for _ in range(int(readline())):
    n, m, q = map(int, readline().split())
    blocks, papers, papers_w, papers_h, queries = [], [], [], [], []
    for _ in range(n):
        x, y = map(lambda k: int(k) - 1, readline().split())
        blocks.append((x, y))
    for _ in range(m):
        w, h = map(lambda k: int(k) - 1, readline().split())
        papers_w.append(w)
        papers_h.append(h)
        papers.append((w, h))
    for _ in range(q):
        l, u = map(int, readline().split())
        queries.append((l, u))

    blocks.sort()
    papers.sort()
    papers_w.sort()
    papers_h.sort()

    papers_wh = []
    blockCoverCnts = []

    pi = 0
    for bi in range(0, n):
        pj = pi
        while pi < m and papers[pi][0] < blocks[bi][0]:
            pi += 1

        while pj < pi:
            insort(papers_wh, papers[pj][1])
            pj += 1

        a = bisect_left(papers_wh, blocks[bi][1])
        b = bisect_left(papers_w, blocks[bi][0])
        c = bisect_left(papers_h, blocks[bi][1])
        tot = m - b - c + a
        blockCoverCnts.append(tot)

    blockCoverCnts.sort()
    ans = []
    for l, u in queries:
        ans.append(str(bisect_right(blockCoverCnts, u) - bisect_left(blockCoverCnts, l)))

    print(' '.join(ans))
