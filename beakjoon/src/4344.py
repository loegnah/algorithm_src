T = int(input())

for t in range(T):
	inputnum = input().split()
	N = int(inputnum[0])
	sum = 0

	for n in range(N):
		sum += int(inputnum[n+1])

	avg = sum//(N*1.0)
	up = 0
	for n in range(N):
		if int(inputnum[n+1]) > avg:
			up += 1

	print("%.3f%%" % (up//(N*1.0)*100))