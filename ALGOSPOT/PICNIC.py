# -*- coding: utf-8 -*-

def Pair():
    first = -1
    for i in range(n):
        if not isFind[i]:
            first = i
            break
    if first == -1:
        return 1

    ret = 0
    for cur in range(first + 1, n):
        if not isFind[cur] and isFriend[first][cur]:
            isFind[first] = isFind[cur] = True
            ret += Pair()
            isFind[first] = isFind[cur] = False

    return ret


c = int(input())

for _ in range(c):
    n, m = map(int, input().split())
    temp = list(map(int, input().split()))

    isFriend = [[False for _ in range(n)] for _ in range(n)]
    for i in range(0,m*2,2):
        isFriend[temp[i]][temp[i + 1]] = True
        isFriend[temp[i + 1]][temp[i]] = True
    isFind = [False for _ in range(n)]

    print(Pair())

