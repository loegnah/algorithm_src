import sys
from collections import deque

readline = sys.stdin.readline
dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def checkCanVisit(y, x, Y, X):
    return y >= 0 and x >= 0 and x < X and y < Y


def solve(Y, X, board):
    isVisited = [[False for _ in range(X + 5)] for _ in range(Y + 5)]
    dist = [[987654321 for _ in range(X + 5)] for _ in range(Y + 5)]
    dqB = deque()
    dqB.append((0, 0, 0))
    while dqB:
        y, x, d = dqB.popleft()
        if isVisited[y][x]:
            continue
        dist[y][x] = d
        isVisited[y][x] = True
        if board[y][x] == '1':
            continue
        for k in range(4):
            ny, nx = y + dirs[k][0], x + dirs[k][1]
            if checkCanVisit(ny, nx, Y, X) and (not isVisited[ny][nx]):
                dqB.append((ny, nx, d + 1))
    dqB = deque()
    dqB.append((Y - 1, X - 1, 0))
    isVisited = [[False for _ in range(X + 5)] for _ in range(Y + 5)]
    distB = [[987654321 for _ in range(X + 5)] for _ in range(Y + 5)]
    while dqB:
        y, x, d = dqB.popleft()
        if isVisited[y][x]:
            continue
        distB[y][x] = d
        isVisited[y][x] = True
        if board[y][x] == '1':
            continue
        for k in range(4):
            ny, nx = y + dirs[k][0], x + dirs[k][1]
            if checkCanVisit(ny, nx, Y, X) and (not isVisited[ny][nx]):
                dqB.append((ny, nx, d + 1))
    minDist = 9876554321
    for y in range(Y):
        for x in range(X):
            # if minDist > dist[y][x] + distB[y][x]:
            #     print(y, x, minDist, dist[y][x], distB[y][x])
            minDist = min(minDist, dist[y][x] + distB[y][x])
    print(minDist + 1 if minDist != 987654321 else -1)


def main():
    N, M = map(int, readline().split())
    board = []
    for _ in range(N):
        board.append(readline())
    solve(N, M, board)


main()
