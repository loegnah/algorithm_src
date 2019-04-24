arr = [0]*10

N = int(input())

while N>0:
	arr[N%10] += 1
	N = N//10

arr[6] = (arr[6]+arr[9]+1)//2
arr[9] = arr[6]

mx = 0
for i in arr:
	if(mx<i): mx = i

print(mx)