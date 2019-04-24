import math

def isPrime(a):
    b = int(math.sqrt(a))
    for i in range(2,b+1):
        if (a%i) == 0:
            return False
    return True

n = int(input())
arr = [[] for _ in range(8)]
arr[0] = [2,3,5,7]
for i in range(1,n):
    for j in arr[i-1]:
        for k in range(10):
            tmp = 10*j+k
            if(isPrime(tmp)):
                arr[i].append(tmp)

for a in arr[n-1]:
    print(a)

