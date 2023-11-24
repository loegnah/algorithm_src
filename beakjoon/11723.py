# 파이썬이라 그런지 시간초과로 안됨.

n = int(input())
isIn = [False for _ in range(21)]

for _ in range(n):
    ipt = list(input().split())
    if len(ipt) == 1:
        cmd = ipt[0]
    else:
        cmd, nums = ipt
        nums = int(nums)
        c = [0 for _ in range(nums)]

    if cmd == 'all':
        for i in range(1, 21):
            isIn[i] = True
    elif cmd == 'empty':
        for i in range(1, 21):
            isIn[i] = False
    elif cmd == 'add':
        isIn[nums] = True
    elif cmd == 'remove':
        isIn[nums] = False
    elif cmd == 'check':
        if (isIn[nums]):
            print(1)
        else:
            print(0)
    else:
        isIn[nums] = 1 - isIn[nums]
