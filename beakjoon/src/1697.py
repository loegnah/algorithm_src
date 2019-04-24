MX = 100001
isVisited = [False for _ in range(MX*2)]
qu = [[],[]]

N,K = map(int,input().split())

ans = -1
if N==K: ans = 0
else:
    isVisited[N] = True
    dist = 0
    qu[0].append(N)
    while True:
        qi = dist%2
        while qu[qi]:
            cur = qu[qi].pop()
            if cur == K:
                ans = dist
                break

            nxt = cur*2
            if (nxt <= MX) and (not isVisited[nxt]):
                isVisited[nxt] = True
                qu[1-qi].append(nxt)
            nxt = cur +1
            if (nxt <= MX) and (not isVisited[nxt]):
                isVisited[nxt] = True
                qu[1 - qi].append(nxt)
            nxt = cur - 1
            if (nxt >= 0) and (not isVisited[nxt]):
                isVisited[nxt] = True
                qu[1 - qi].append(nxt)
        if ans != -1: break
        dist += 1

print(ans)
