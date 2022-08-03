import queue

N,M,V = map(int,input().split())
adj = [[0 for _ in range(N+1)] for _ in range(N+1)]
for _ in range(M):
	a,b = map(int,input().split())
	adj[a][b] = 1
	adj[b][a] = 1
abc = [(N,0,-1),(1,N+1,1)]

def dfsbfs(q,db):
	ret = []
	a,b,c = abc[db]
	isVisited = [False for _ in range(N+1)]
	visitCt = N
	q.put(V)
	while True:
		if(visitCt == 0): break
		cur = q.get()
		if(isVisited[cur]): continue
		visitCt -= 1
		isVisited[cur] = True
		ret.append(str(cur))
		for i in range(a,b,c):
			if adj[cur][i] == 1:
				q.put(i)
	return ret


q = queue.LifoQueue()
dfsRet = ' '.join(dfsbfs(q,0))
print(dfsRet)
q = queue.Queue()
dfsRet = ' '.join(dfsbfs(q,1))
print(dfsRet)



