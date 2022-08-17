from sys import stdin

readline = stdin.readline

arr = []
for _ in range(int(readline())):
    x, y = map(int, readline().split())
    arr.append((x, y))

for x, y in sorted(arr, key=lambda k: (k[1], k[0])):
    print(x, y)
