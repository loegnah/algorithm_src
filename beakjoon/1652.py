N = int(input())
arr = [0 for i in range(N)]
for i in range(N):
	arr[i] = input()
a = 0
for i in range(N):
	ck = 0
	for j in range(N):
		if(arr[i][j] == 'X'):
			if(ck>=2): a += 1
			ck = 0
		else:
			ck += 1
	if(ck>=2):
		a += 1
b = 0
for i in range(N):
	ck = 0
	for j in range(N):
		if(arr[j][i] == 'X'):
			if(ck>=2): b += 1
			ck = 0
		else:
			ck += 1
	if(ck>=2):
		b += 1

print(a,b)