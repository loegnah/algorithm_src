from sys import stdin, stdout

def solve(dat):
  n, k = len(dat), len(dat[0])
  cnt = [dict() for i in range(k+1)]
  
  for i in range(n):
    cu, counter = 0, [0 for j in range(26)]
    for j in range(k):
      if 'A' <= dat[i][j] and dat[i][j] <= 'Z':
        cu += 1
      v = ord(dat[i][j]) - ord('A') if dat[i][j] <= 'Z' else ord(dat[i][j]) - ord('a')
      counter[v] += 1
    counter = tuple(counter)
    if counter not in cnt[cu]:
      cnt[cu][counter] = 0
    cnt[cu][counter] = cnt[cu][counter] + 1
  
  ans = 0
  for i in range(k+1):
    for _, v in cnt[i].items():
      ans += (v * (v-1)) // 2 
  return ans

def parse(x):
  tok = x.split(':')
  return int(tok[0])*3600 + int(tok[1])*60 + int(tok[2])

t = int(stdin.readline().rstrip())
while t > 0:
  t-=1
  n, k = map(int, stdin.readline().rstrip().split())
  dat = stdin.readline().rstrip().split()
  
  ans = solve(dat)
  stdout.write('%d\n' % ans)
  stdout.flush()
  
