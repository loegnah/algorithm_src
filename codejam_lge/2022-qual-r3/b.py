import sys

readline = sys.stdin.readline
MOD = pow(10, 9) + 7

T = int(readline())
for _ in range(T):
    n, k = map(int, readline().split())
    arr = readline()

    if k == 1:
        print(1)
        continue

    cntZeroBehindOne = []
    pre = 0
    for i, a in enumerate(arr):
        if a == '1':
            cntZeroBehindOne.append(i - pre)
            pre = i + 1
    cntOne = len(cntZeroBehindOne)

    if k > cntOne or (cntOne % k != 0):
        print(0)
        continue

    sizePiece = cntOne // k
    ans = 1
    for i in range(sizePiece, cntOne, sizePiece):
        ans = (ans * (cntZeroBehindOne[i] + 1)) % MOD

    print(ans)
