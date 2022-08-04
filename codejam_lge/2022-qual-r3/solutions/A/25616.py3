from sys import stdin, stdout
def gcd(x, y):
  while y > 0:
    z = x % y
    x = y
    y = z
  return x
  
def solve(a, b, c):
  g = gcd(a, b)
  return c // g

t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  a, b, c = map(int, stdin.readline().rstrip().split())

  ans = solve(a, b, c)

  stdout.write("%d\n" % ans)
  stdout.flush()
