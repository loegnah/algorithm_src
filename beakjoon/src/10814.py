import sys

readline = sys.stdin.readline

n = int(readline())
users = [[] for _ in range(201)]

for _ in range(n):
    age, name = readline().split()
    users[int(age)].append(name)

for age, names in enumerate(users):
    for name in names:
        print(age, name)
