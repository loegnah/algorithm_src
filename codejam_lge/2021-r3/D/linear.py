from sys import stdin, stdout


def solve(n, z, h, w, v):
  maxi = -1
  nb, ib = 1, 0
  bg = [0 for i in range(n)]
  
  for i in range(1, n):
    while (ib < nb and h[i] - h[bg[ib]] > z):
      ib+= 1
    
    if ib < nb:
      maxi = max(maxi, v[i] + v[bg[ib]])
    
    while ib < nb and v[i] >= v[bg[nb-1]]:
      nb -= 1
    bg[nb] = i
    nb+= 1
  
  return maxi

t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  n, z = map(int, stdin.readline().rstrip().split())
  hs,ha,hb,hc = map(int, stdin.readline().rstrip().split())
  ws,wa,wb,wc = map(int, stdin.readline().rstrip().split())
  
  H, W = [0 for i in range(n)], [0 for i in range(n)]
  
  H[0] = hs % hc + 1
  for i in range(1, n):
    H[i] = H[i-1] + 1 + (H[i-1] * ha + hb) % hc
  
  W[0] = ws % wc + 1
  for i in range(1, n):
    W[i] = (W[i-1] * wa + wb) % wc + 1
    
  h = [H[i] for i in range(n)]
  w = [W[i] for i in range(n)]
  v = [h[i]*w[i] for i in range(n)]

  ans = solve(n, z, h, w, v)
  stdout.write("%d\n" % ans)
  stdout.flush()

