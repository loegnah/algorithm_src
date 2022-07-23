import sys

readline = sys.stdin.readline
PLUS, DOT, AXE, BARw, BARh = '+', '.', 'X', '-', '|'


def getDiceValue(y, x):
    value = 0
    if y > H - 5 or x > W - 5:
        return -1
    for yy in range(y+1, y+4):
        for xx in range(x+1,x+4):
            if planar[yy][xx] == AXE:
                value |=

H, W = map(int, readline().split())
planar = []
for y in range(H):
    planar.append(readline().strip())

visited = [[False] * W for _ in range(H)]
