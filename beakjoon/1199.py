N = int(input())
adj = [[0 for _ in range(N)] for _ in range(N)]
lineSum = [0 for _ in range(N)]
searchStt = [0 for _ in range(N)]
tot = 0
for i in range(N):
	tmp = list(map(int,input().split()))
	for j in range(i+1,N):
		k = tmp[j]
		if k>0 :
			adj[i][j] = k
			adj[j][i] = k
			lineSum[i] += k
			lineSum[j] += k
			tot += k

ck = True
for s in lineSum:
	if s%2 == 1:
		ck = False
		break

if ck:
	cur = 0
	for s in range(N-1,-1,-1):
		if lineSum[s] != 0:
			cur = s
			break

	trc = [str(cur+1)]
	while tot > 0:
		for i in range(searchStt[cur],N):
			if adj[cur][i] > 0:
				adj[cur][i] -= 1
				adj[i][cur] -= 1
				searchStt[cur] = i
				cur = i
				tot -= 1
				trc.append(str(i+1))
				break
	print(' '.join(trc))