N_point,N_line = map(int,input().split())
start = int(input())

graph = []
for _ in range(N_point+1):
    graph.append({})

for _ in range(N_line):
    u,v,w = map(int,input().split())
    if graph[u].get(v) == None:
        graph[u][v] = w
    else:
        graph[u][v] = min(graph[u][v],w)

'''
### check ###
for i in range(N_point):
    print(graph[i+1])
'''
INF = 9999999999
lines = {}
ans = [INF] * (N_point+1)
ans[start] = 0
cur = start
cur_w = 0
while True:
    if cur==-1:
        break
    for dst,dst_w in graph[cur].items():
        if ans[dst] == INF:
            if lines.get(dst) == None:
                lines[dst] = dst_w + cur_w
            else:
                lines[dst] = min(lines[dst],(dst_w + cur_w))

    next_w = 11
    next = -1
    for a,a_w in lines.items():
        if next_w > a_w and ans[a] == INF:
            next = a
            next_w = a_w
    if next != -1:
        ans[next] = next_w
    cur = next
    cur_w = next_w

for i in range(1,N_point+1):
    if ans[i] == INF:
        print("INF")
    else:
        print(ans[i])

