def solve():
    N,M,x,y = map(int,input().split())

    a = 0
    b = 0
    ans = 0
    isChecked = set()

    while a-b != x-y:
        t = min(N-a,M-b)
        cac = (a+t,b+t)
        
        if cac in isChecked:
            return -1
        
        isChecked.add(cac)
        ans += t
        a = (a+t)%N
        b = (b+t)%M

    ans += x-a
    return ans

for _ in range(int(input())):
    print(solve())
    
