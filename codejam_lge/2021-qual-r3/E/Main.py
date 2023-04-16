from sys import stdin, stdout

def has_aug():
  
  return True

def solve(val, to):
  n, m, SRC, SNK = len(val), len(to), len(val), len(val)+1
  
  sorted(to)
  
  f = [[0 for i in range(n+2)] for i in range(n+2)]
  c = [[0 for i in range(n+2)] for i in range(n+2)]
  nei = [[] for i in range(n+2)]
  for i in range(m):
    c[to[i][0]][to[i][1]] = to[i][2]
  
  for i in range(n+2):
    for j in range(n+2):
      if c[i][j] > 0 or c[j][i] > 0:
        nei[i].append(j)
      
  tot_flow, tot_pos = 0, sum(filter(lambda x: x > 0, val))
  
  vis = [False for i in range(n+2)]
  fr = [0 for i in range(n+2)]
  qu = [0 for i in range(n+2)]
  path = [0 for i in range(n+2)]
  
  while True:
    front, rear = 0, 0
    for i in range(n+2):
      vis[i] = False
    fr[SRC], vis[SRC], qu[rear] = -1, True, SRC
    rear += 1
    
    while front < rear:
      x = qu[front]
      front += 1
      for y in nei[x]:
        if (not vis[y]) and f[x][y] < c[x][y]:
          vis[y], fr[y], qu[rear] = True, x, y
          rear += 1
      
    if not vis[SNK]:
      break
    
    np, x, aug_val = 0, SNK, 1048576
    while True:
      path[np], y = x, fr[x]
      np += 1
      if y == -1:
        break
      aug_val = min(aug_val, c[y][x] - f[y][x])
      x = y
    
    tot_flow += aug_val
    for i in range(1, np):
      y, x = path[i-1], path[i]
      f[x][y] += aug_val
      f[y][x] -= aug_val
    
  return tot_pos - tot_flow

t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  n, m = map(int, stdin.readline().rstrip().split())
  val = list(map(int, stdin.readline().rstrip().split()))
  to = [[0 for j in range(3)] for i in range(n+m)]
  for i in range(m):
    x, y, z = map(int, stdin.readline().rstrip().split())
    to[i][0], to[i][1], to[i][2] = x-1, y-1, z
  
  SRC, SNK = n, n+1
  for i in range(n):
    if val[i] > 0:
      to[m+i][0], to[m+i][1], to[m+i][2] = SRC, i, val[i]
    else:
      to[m+i][0], to[m+i][1], to[m+i][2] = i, SNK, -val[i]
    
  ans = solve(val, to)
  stdout.write("%d\n" % ans)
  stdout.flush()
  



