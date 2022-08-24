from sys import stdin

readline = stdin.readline

n, m = map(int, readline().split())
nameArr, nameMap = [0] * (n + 1), {}

for i in range(1, n + 1):
    name = readline().rstrip()
    nameArr[i] = name
    nameMap[name] = i

ans = ''
for _ in range(m):
    ipt = readline().rstrip()
    res = nameArr[int(ipt)] if ipt.isnumeric() else str(nameMap[ipt])
    ans += res + '\n'
print(ans)
