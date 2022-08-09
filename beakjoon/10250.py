import sys

readline = sys.stdin.readline

for _ in range(int(readline())):
    H, W, N = map(int, readline().split())
    a = ((N - 1) % H) + 1
    b = ((N - 1) // H) + 1
    print(f'{a}{b:02d}')
