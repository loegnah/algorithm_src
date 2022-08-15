from sys import stdin

readline = stdin.readline

people = []

for _ in range(int(readline())):
    x, y = map(int, readline().split())
    people.append((x, y))

ranks = []
for a in people:
    rank = 1
    for b in people:
        if a[0] < b[0] and a[1] < b[1]:
            rank += 1
    ranks.append(rank)
print(' '.join(map(str, ranks)))
