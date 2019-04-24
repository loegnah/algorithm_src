T = int(input())

for _ in range(T):
    n = int(input())
    mx = n

    while n != 1:
        if n%2: n = n*3+1
        else: n //= 2

        if mx<n: mx = n

    print(mx)