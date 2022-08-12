import sys

N, K = map(int, sys.stdin.readline().split())

people = [i for i in range(1, N + 1)]
removed = []
idx = 0

while people:
    idx = (idx + K - 1) % len(people)
    removed.append(str(people.pop(idx)))
print(f"<{', '.join(removed)}>")
