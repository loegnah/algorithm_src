from sys import stdin, stdout

def ok(todo, i, j, d):
  if d[i][0] >= d[j][0]:
    return False
  if i == 0 and j == n:
    return False
  return i == 0 or (todo == 0 and d[i][1] < d[j][1]) or (todo == 1 and d[i][1] > d[j][1])

def doit(i, j, x, y, dp, fr, d):
  if i == 0 and j == 1:
    return 1
  
  ret = dp[i][j][x][y]
  if ret != -1:
    return ret
  
  ret = 0
  
  if i+1 == j:
    for k in range(0, i):
      if ok(1-y, k, j, d):
        ret = doit(k, i, 1-y, x, dp, fr, d)
        if ret != 0:
          fr[i][j][x][y] = k
          break
  else:
    if ok(1-y, j-1, j, d):
      ret = doit(i, j-1, x, 1-y, dp, fr, d)
      if ret != 0:
        fr[i][j][x][y] = j-1
  
  dp[i][j][x][y] = ret
  return ret

def solve(n, d1, d2):
  v = [[d1[i], d2[i]] for i in range(n)]
  d = [[v[i-1][0] if i > 0 else 0, v[i-1][1] if i > 0 else 0, i if i > 0 else 0] for i in range(n+1)]
  d.sort()
  
  dp = [[[[-1 for l in range(2)] for k in range(2)] for j in range(n+1)] for i in range(n+1)]
  fr = [[[[-1 for l in range(2)] for k in range(2)] for j in range(n+1)] for i in range(n+1)]
  
  for i in range(1, n):
    for x in range(2):
      if doit(i,n,x,1-x,dp,fr,d) == 1 and ok(x,i,n,d):
        y,j,sig = 1-x, n, 0
        p = [[], []]
        while True:
          k = fr[i][j][x][y]
          p[1-sig].append(j)
          if k == -1:
            break
          if i+1 == j:
            sig = 1-sig
            j = i
            i = k
            tmp = x
            x = 1-y
            y = tmp
          else:
            j-=1
            y = 1-y

        ans = []
        for l in range(len(p[0])-1, -1, -1):
          ans.append(d[p[0][l]][2])
        for l in range(len(p[1])):
          ans.append(d[p[1][l]][2])
        return ans
        
  return []

t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  n = int(stdin.readline().rstrip())
  d1 = list(map(int, stdin.readline().rstrip().split()))
  d2 = list(map(int, stdin.readline().rstrip().split()))
  
  ans = solve(n, d1, d2)
  if len(ans) == 0:
    stdout.write("-1\n")
  else:
    
    stdout.write(" ".join(map(lambda x: str(x), ans)) + "\n")
    
  stdout.flush()
  


