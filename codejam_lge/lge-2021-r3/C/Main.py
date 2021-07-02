from sys import stdin, stdout

def gcd(x, y):
  while y > 0:
    z = x % y
    x = y
    y = z
  return x

def exp(x, e, m):
  if e <= 1:
    return x if e == 1 else 1
  
  ans = exp(x, e//2, m)
  ans = (ans * ans) % m
  if e % 2 == 1:
    ans = (ans * x) % m
  return ans

def inv(aa, mm):
  phi, m_org = 1, mm
  for dv in range(2, 6):
    cp = 0
    while m_org > 1 and m_org % dv == 0:
      m_org //= dv
      cp += 1
    if cp > 0:
      for k in range(cp):
        phi *= dv
      phi *= dv-1
  return exp(aa, phi-1, mm)

def solve(dat, tim):
  n, M, ans = len(dat), 24*60*60, 0
  val = [-1 for i in range(M+1)]
  nv = [0 for i in range(M+1)]
  cnt = [0 for i in range(M+1)]
  
  for i in range(1, n):
    a, b = ((dat[i] - dat[0]) + M ) % M, ((tim[0] - tim[i]) + M ) % M
    g = gcd(a, M)
    if b % g != 0:
      return 0
    aa, bb, mm = a//g, b//g, M//g
    x = (bb * inv(aa, mm)) % mm
    
    if val[mm] != -1 and val[mm] != x:
      return 0
    
    val[mm] = x
    nv[mm] += 1
  
  for mm in range(1, M+1):
    if val[mm] != -1:
      for x in range(val[mm], M, mm):
        cnt[x] += nv[mm]
        if cnt[x] == n-1:
          ans+= 1
  return ans

def parse(x):
  tok = x.split(':')
  return int(tok[0])*3600 + int(tok[1])*60 + int(tok[2])

t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  n = int(stdin.readline().rstrip())
  tim = list(map(lambda x : parse(x), stdin.readline().rstrip().split()))
  dat = list(map(int, stdin.readline().rstrip().split()))
  ans = solve(dat, tim)
  stdout.write('%d\n' % ans)
  stdout.flush()
  

