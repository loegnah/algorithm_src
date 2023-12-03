import sys
from collections import deque

readline = sys.stdin.readline


def solve(N: int, papers: list[list[int]]):
    qu = deque()
    qu.append((0, 0, N))

    def isAllSame():
        sy, sx, sz = qu.popleft()
        baseColor = papers[sy][sx]
        for y in range(sy, sy + sz):
            for x in range(sx, sx + sz):
                if papers[y][x] != baseColor:
                    szHalf = sz // 2
                    qu.append((sy, sx, szHalf))
                    qu.append((sy, sx + szHalf, szHalf))
                    qu.append((sy + szHalf, sx, szHalf))
                    qu.append((sy + szHalf, sx + szHalf, szHalf))
                    return -1
        return baseColor

    white, blue = 0, 0
    while qu:
        checkRet = isAllSame()
        if checkRet == -1:
            continue
        if checkRet == 0:
            white += 1
        else:
            blue += 1
    print(white)
    print(blue)


def main():
    N = int(readline())
    papers = [list(map(int, readline().split())) for _ in range(N)]
    solve(N, papers)


main()
