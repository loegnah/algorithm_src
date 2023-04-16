from sys import stdin, stdout

def doit(d, last, x, val, n):
  global ans
  if d == n:
    ans += 1
    return
  nxt = 0
  for i in range(d, n):
    nxt = nxt*16 + val[i]
    if nxt >= last:
      doit(i+1, nxt, x, val, n)

def solve(x):
  n = len(x)
  val = [0 for i in range(n)]
  for i in range(n):
    if ord(x[i]) <= ord('9'):
      val[i] = ord(x[i]) - ord('0')
    else:
      val[i] = ord(x[i]) - ord('A') + 10
  
  global ans
  
  ans = 0
  doit(0, 0, x, val, n)
  
  return ans

t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  x = stdin.readline().rstrip()
  ans = solve(x)
  stdout.write('%d\n' % ans)
  stdout.flush()
  
