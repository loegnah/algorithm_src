import sys
from collections import deque

readline = sys.stdin.readline

dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def find_start(board):
    Y, X = len(board), len(board[0])
    for y in range(Y):
        for x in range(X):
            if board[y][x] == 2:
                return y, x


def bfs(board, start):
    Y, X = len(board), len(board[0])
    ret = [[-1] * X for _ in range(Y)]
    visited = [[False] * X for _ in range(Y)]
    visited[start[0]][start[1]] = True
    queue = deque([(start[0], start[1], 0)])
    while queue:
        y, x, d = queue.popleft()
        if board[y][x] == 0:
            ret[y][x] = 0
            continue
        ret[y][x] = d
        for dy, dx in dirs:
            ny, nx = y + dy, x + dx
            if 0 <= ny < Y and 0 <= nx < X and not visited[ny][nx]:
                visited[ny][nx] = True
                queue.append((ny, nx, d + 1))
    return ret


def set_already_zero_to_zero(board, dists):
    Y, X = len(board), len(board[0])
    for y in range(Y):
        for x in range(X):
            if board[y][x] == 0:
                dists[y][x] = 0


def main():
    n, m = map(int, readline().split())
    board = []
    for _ in range(n):
        board.append(list(map(int, readline().split())))

    start = find_start(board)
    dists = bfs(board, start)
    set_already_zero_to_zero(board, dists)
    for i in range(n):
        print(" ".join(map(str, dists[i])))


main()
