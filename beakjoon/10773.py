from sys import stdin

readline = stdin.readline

stack = []
ans = 0
for _ in range(int(readline())):
    n = int(readline())
    if n == 0:
        ans -= stack.pop()
    else:
        stack.append(n)
        ans += n
print(ans)
