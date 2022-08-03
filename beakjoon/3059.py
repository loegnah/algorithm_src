n = int(input())
count2 = 0
count5 = 0

for a in range(1,n+1):
    while a%2==0:
        count2 += 1 
        a //= 2
    while a%5==0:
        count5 += 1
        a //= 5

print(min(count2,count5))