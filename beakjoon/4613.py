num = list(26)
num[]

T = int(input())
for tc in range(T):
    N,M = map(int,input().split())
    line = ""
    ss = [[0,0,0] for i in range(N)]

    for i in range(N):
        line = input()
        for j in range(M):
