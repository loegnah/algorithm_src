def sol(n, m):
    if m>n : return sol(m,n)
    
    while m != 0:
        n,m = (m,n%m)
    
    return n

N, M = map(int,input().split(':'))
k = sol(N,M)
print("{}:{}".format(N//k,M//k))