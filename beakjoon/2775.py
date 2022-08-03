top = 15
arr = [[0 for i in range(top)] for j in range(top)]

for i in range(top):
	arr[0][i] = i

for i in range(1,top):
	for j in range(1,top):
		arr[i][j] = arr[i][j-1] + arr[i-1][j]

T = int(input())
for t in range(T):
	k = int(input())
	n = int(input())
	print(arr[k][n])