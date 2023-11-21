import sys
from collections import deque

readline = sys.stdin.readline


def solve(N, M, extracts):
    dq = deque(range(1, N + 1))
    totMoveCnt = 0

    for ex in extracts:
        moveCnt = 0
        while dq[0] != ex:
            moveCnt += 1
            dq.append(dq.popleft())
        totMoveCnt += min(moveCnt, len(dq) - moveCnt)
        dq.popleft()
    return totMoveCnt


def main():
    N, M = map(int, readline().split())
    extracts = map(int, readline().split())
    ans = solve(N, M, extracts)
    print(ans)


main()
