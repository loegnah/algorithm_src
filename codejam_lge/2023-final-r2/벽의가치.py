import sys
from collections import deque

readline = sys.stdin.readline

dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def bfs(dist_map, start_r, start_c):
    global board
    dq = deque([(start_r, start_c, 0)])
    while len(dq):
        r, c, dist = dq.popleft()
        if dist_map[r][c] != -1:
            continue
        dist_map[r][c] = dist
        if board[r][c] == 'W':
            continue
        for dr, dc in dir:
            nr, nc = r + dr, c + dc
            if 0 <= nr < R and 0 <= nc < C and dist_map[nr][nc] == -1:
                dq.append((nr, nc, dist + 1))


T = int(readline())
for _ in range(T):
    R, C, N, goal_r, goal_c = map(int, readline().split())
    goal, mals = (goal_r - 1, goal_c - 1), [0] * N
    for i in range(N):
        Ri, Ci = map(int, readline().split())
        mals[i] = (Ri - 1, Ci - 1)

    board, walls = [], []
    for r in range(R):
        line = readline().strip()
        board.append(line)
        for c in range(C):
            if line[c] == 'W':
                walls.append((r, c))
    distGoal = [[-1] * C for _ in range(R)]
    distMals = [[[-1] * C for _ in range(R)] for _ in range(N)]
    bfs(distGoal, goal[0], goal[1])
    for i in range(N):
        bfs(distMals[i], mals[i][0], mals[i][1])

    ans1, ans2 = 0, 0
    for i, mal in enumerate(mals):
        originDist = distGoal[mal[0]][mal[1]]
        ans1 += originDist
        for wall in walls:
            distGoalToWall = distGoal[wall[0]][wall[1]]
            distMalToWall = distMals[i][wall[0]][wall[1]]
            afterDist = distGoalToWall + distMalToWall
            if distGoalToWall != -1 and distMalToWall != -1 and afterDist < originDist:
                ans2 += originDist - afterDist
    print(ans1, ans2)
