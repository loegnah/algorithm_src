from sys import stdin, stdout

def satisfied(p, x1, y1, x2, y2):
  global sums, pref
  t = pref[p]
  cnt = sums[t][x2][y2] + sums[t][x1-1][y1-1] - sums[t][x1-1][y2] - sums[t][x2][y1-1]
  return cnt >= 1

def solve():
  global sums, pref, r, c, n
  for k in range(3):
    for i in range(1, r+1):
      for j in range(1, c+1):
        sums[k][i][j] += sums[k][i-1][j];
        sums[k][i][j] += sums[k][i][j-1];
        sums[k][i][j] -= sums[k][i-1][j-1];

  dp = [[[-1 for _ in range(n)] for _ in range(c+1)] for _ in range(r+1)]
  
  MOD = 1000000007
  for k in range(n-1, -1, -1):
    for x in range(r, 0, -1):
      for y in range(c, 0, -1):
        dp[x][y][k] = 0
        if k == n-1:
          dp[x][y][k] = 1 if satisfied(k, x, y, r, c) else 0
          continue

        for i in range(x, r):
          if(not satisfied(k, x, y, i, c)):
            continue
          dp[x][y][k] += dp[i+1][y][k+1]
          dp[x][y][k] %= MOD

        for j in range(y, c):
          if(not satisfied(k, x, y, r, j)): 
            continue
          dp[x][y][k] += dp[x][j+1][k+1]
          dp[x][y][k] %= MOD
  return dp[1][1][0]
  
  
global sums, pref, dp, r, c, n
t = int(stdin.readline().rstrip())
S, R, B = 0, 1, 2
while t > 0:
  t-=1
  r, c, n = map(int, stdin.readline().rstrip().split())

  sums = [[[0 for _ in range(c+1)] for _ in range(r+1)] for _ in range(3)]
  for i in range(1, r+1):
    line = stdin.readline().rstrip()
    for j in range(1, c+1):
      cell = -1
      if line[j-1] == 'S':
        cell = S
      elif line[j-1] == 'R':
        cell = R
      elif line[j-1] == 'B':
        cell = B
      if cell != -1:
        sums[cell][i][j] = 1
  
  pref = [0 for _ in range(n)]
  line = stdin.readline().rstrip()
  for i in range(n):
    if line[i] == 'S':
      pref[i] = S
    elif line[i] == 'R':
      pref[i] = R
    elif line[i] == 'B':
      pref[i] = B
    
  ans = solve()
  stdout.write("%d\n" % (ans))
  stdout.flush()

