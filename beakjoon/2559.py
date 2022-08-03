N,K = map(int,input().split())
ipt = list(map(int,input().split()))

ans = 0
tmp = 0
for i in range(K):
    ans += ipt[i]
tmp = ans

for i in range(K,N):
    tmp -= ipt[i-K]
    tmp += ipt[i]
    if ans<tmp :
        ans = tmp

print(ans)