import sys

# main
n = int(sys.stdin.readline())
tree = [[] for _ in range(n+1)]
lengthCache = [0 for _ in range(n*3)]
ans = -1

# input
for i in range(n-1):
    parent, child, length = map(int,sys.stdin.readline().split())
    tree[parent].append((child,length))

for cur in range(n,0,-1):
    lf = rt = lfLength = rtLength = 0

    if len(tree[cur]) :
        lf, lfLength = tree[cur][0]
        if len(tree[cur]) > 1:
            rt, rtLength = tree[cur][1]

    if lf:
        lfLength += lengthCache[lf]
    if rt:
        rtLength += lengthCache[rt]
    ans = ans if ans > lfLength+rtLength else lfLength+rtLength
    lengthCache[cur] = max(lfLength,rtLength)

print(ans)
