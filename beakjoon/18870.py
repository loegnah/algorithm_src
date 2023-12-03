import sys

readline = sys.stdin.readline

N = int(readline().strip())
X = list(map(int, readline().split()))
X_dict = {x: i for i, x in enumerate(sorted(set(X)))}

ans = map(lambda x: str(X_dict[x]), X)
print(' '.join(ans))
