N = int(input())
if N<100:
	print(N)
else:
	ans = 99
	for i in range(100,N+1):
		n1 = i%10
		i = i//10
		n2 = i%10
		i = i//10
		n3 = i
		if (n3-n2)==(n2-n1):
			ans += 1
	print(ans)
