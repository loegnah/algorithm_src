n = int(input())
MOD = 10007
arr = [i for i in range(1,11)]
for i in range(n-1):
    for j in range(1,10):
        arr[j] = (arr[j-1] + arr[j]) % MOD
print(arr[9])
