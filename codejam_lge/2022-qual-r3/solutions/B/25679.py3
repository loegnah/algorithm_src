from sys import stdin, stdout

def pow_mod(x, e):
  MOD = 1000000000 + 7
  if e == 0:
    return 1
  if e == 1:
    return x
  
  x2 = pow_mod(x, e//2)
  x2 = (x2 * x2) % MOD
  if e % 2 == 1:
    x2 = (x2 * x) % MOD
  return x2

def binom_mod(nn, kk):
  MOD = 1000000000 + 7
  if(kk < 0 or kk > nn or nn < 0):
    return 0
  if(nn == kk or kk == 0):
    return 1
  
  ans = 1
  for num in range(nn-kk+1, nn+1):
    ans = (ans * num) % MOD
  for num in range(1, kk+1):
    ans = (ans * pow_mod(num, MOD-2)) % MOD
  return ans


def solve(n, k, arr):
  MOD = 1000000000 + 7
  ind = [0 for _ in range(n+1)]
  
  cnt = 0
  for i in range(n):
    if arr[i] == '1':
      cnt += 1
      ind[cnt] = i
  
  if cnt % k != 0:
    return 0
  
  if cnt == 0:
    return binom_mod(n-1, k-1)
  
  unit, ans = cnt//k, 1
  
  for i in range (1, k):
    i1, i2 = ind[unit*i], ind[unit*i + 1]
    ans = ans * (i2 - i1)
    ans %= MOD

  return ans
  
t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  n, k = map(int, stdin.readline().rstrip().split())
  arr = stdin.readline().rstrip()
  ans = solve(n, k, arr)
  stdout.write("%d\n" % ans)
  stdout.flush()
