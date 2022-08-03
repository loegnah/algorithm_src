N = int(input())

ans = 1 #껍질 수
total = 1
while total<N:
	total = total + 6*ans
	ans += 1
print(ans)
