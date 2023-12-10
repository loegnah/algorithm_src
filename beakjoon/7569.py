import sys
from collections import deque

readline = sys.stdin.readline

dirs = [(1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, 1), (0, 0, -1)]
VISITED = 3

X, Y, Z = map(int, readline().split())
tomatoes, noRipeCnt = [[0] * Y for _ in range(Z)], 0
qu = deque()

for z in range(Z):
    for y in range(Y):
        line = list(map(int, readline().split()))
        tomatoes[z][y] = line
        for x in range(X):
            if line[x] == 1:
                qu.append((x, y, z, 0))
                tomatoes[z][y][x] = VISITED
            elif line[x] == 0:
                noRipeCnt += 1

day = 0
while qu:
    x, y, z, d = qu.popleft()
    day = d
    for dx, dy, dz in dirs:
        nx, ny, nz = x + dx, y + dy, z + dz
        if 0 <= nx < X and 0 <= ny < Y and 0 <= nz < Z and tomatoes[nz][ny][nx] == 0:
            qu.append((nx, ny, nz, d + 1))
            noRipeCnt -= 1
            tomatoes[nz][ny][nx] = VISITED
print(day if noRipeCnt == 0 else -1)
