import bisect, sys

readline = sys.stdin.readline

node = []
for _ in range(int(readline())):
    a, b = map(int, readline().split())
    node.append((a, b))

node.sort()
t = [node[0][1]]

for a, b in node[1:]:
    if b > t[-1]:
        t.append(b)
    else:
        t[bisect.bisect_left(t, b)] = b

print(len(node) - len(t))
