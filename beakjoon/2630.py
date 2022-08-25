import sys


def isAllSame(sY, sX, length):
    color = board[sY][sX]
    for y in range(sY, sY + length):
        for x in range(sX, sX + length):
            if board[y][x] != color:
                nextLn = length // 2
                isAllSame(sY, sX, nextLn)
                isAllSame(sY + nextLn, sX, nextLn)
                isAllSame(sY, sX + nextLn, nextLn)
                isAllSame(sY + nextLn, sX + nextLn, nextLn)
                return
    ans[int(color)] += 1


if __name__ == '__main__':
    readline = sys.stdin.readline
    N = int(readline())
    board = []
    ans = [0, 0]

    for _ in range(N):
        board.append(list(map(int, readline().split())))

    isAllSame(0, 0, N)
    print(ans[0])
    print(ans[1])
