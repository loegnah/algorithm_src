import sys

readline = sys.stdin.readline

readline()
X = list(map(int, sys.stdin.read().split()))
X_dict = {x: i for i, x in enumerate(sorted(set(X)))}

print(' '.join(map(str, map(lambda x: X_dict[x], X))))
