arr = [0]*10001

for i in range(10000):
	sum = i

	while (i!=0) :
		sum += (i%10)
		i = i//10

	if sum > 10000:
		continue

	arr[sum] = 1

for i in range(10001):
	if arr[i]==0 :
		print(i)
