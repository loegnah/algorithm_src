T = int(input())
for _ in range(T):
    n = int(input())
    ans = []
    idx = 0

    while(n):
        if n%2: ans.append(idx)
        n //= 2
        idx += 1

    for i in ans:
        print(i,end=" ")