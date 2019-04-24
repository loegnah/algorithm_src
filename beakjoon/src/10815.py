N = int(input())
arr = list(map(int,input().split()))
arr.sort()

M = int(input())
ans = [0 for _ in range(M)]
idx = 0
for m in map(int,input().split()):
    high = N
    low = 0
    ck = False
    while(low<high):
        mid = (high+low)//2
        if(arr[mid]==m):
            ck = True
            break
        elif(arr[mid]>m):
            high = mid
        else:
            low = mid+1
    if(ck):
        ans[idx] = 1
    idx += 1
for i in ans:
    print(i,end=' ')
        