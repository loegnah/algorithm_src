n,k = map(int,input().split())

arr = [0 for _ in range(k+1)]
arr[0] = 1

for _ in range(n):
    curCoin = int(input())
    for money in range(curCoin,k+1):
        arr[money] += arr[money-curCoin]
print(arr[k])