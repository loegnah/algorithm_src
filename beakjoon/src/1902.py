M, N = map(int,input().split())
isSosu = [True for _ in range(N+1)]
ans = ""

def sosuCheck(a):
    for k in range(a*(M//a),N+1,a):
        isSosu[k] = False

st = 2
while st<M:
    sosuCheck(st)     
    st += 1
    while st<M and not isSosu[st]:
        st += 1

while st<=N:
    if isSosu[st]:
        ans += str(st)+"\n"
        sosuCheck(st)
    st += 1

print(ans, end="")
    

    