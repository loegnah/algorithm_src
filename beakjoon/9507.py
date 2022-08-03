fibo = [1,1,2,4]
for i in range(4,68):
    fibo.append(fibo[i-1] + fibo[i-2] + fibo[i-3] + fibo[i-4])
t = int(input())
for _ in range(t):
    print(fibo[int(input())])
