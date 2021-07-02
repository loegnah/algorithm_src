from sys import stdin, stdout
import heapq

def solve(n, z, h, w, v):
  maxi = -1
  
  qu = []
  for i in range(n):
    while len(qu) > 0 and h[i] - h[qu[0][1]] > z:
      heapq.heappop(qu)
    
    if len(qu) > 0:
      maxi = max(maxi, v[i] - qu[0][0])
      
    heapq.heappush(qu, [-v[i], i])
  return maxi


t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  n, z = map(int, stdin.readline().rstrip().split())
  hs,ha,hb,hc = map(int, stdin.readline().rstrip().split())
  ws,wa,wb,wc = map(int, stdin.readline().rstrip().split())
  
  H, W = [0 for i in range(n)], [0 for i in range(n)]
  
  H[0] = hs % hc + 1
  W[0] = ws % wc + 1
  for i in range(1, n):
    H[i] = H[i-1] + 1 + (H[i-1] * ha + hb) % hc
    W[i] = (W[i-1] * wa + wb) % wc + 1
    
  v = [H[i]*W[i] for i in range(n)]

  ans = solve(n, z, H, W, v)
  stdout.write("%d\n" % ans)
  stdout.flush()

