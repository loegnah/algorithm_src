import sys
from math import lcm

readline = sys.stdin.readline

for _ in range(int(readline())):
    m, n, x, y = map(int, readline().split())
    ans = -1
    lc = lcm(m, n)
    for i in range(0, n):
        year = (m * i) + x
        r = year % n if year % n else n
        if r == y:
            ans = year
            break
    print(ans if ans <= lc else -1)
