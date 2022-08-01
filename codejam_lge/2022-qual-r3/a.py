import sys

readline = sys.stdin.readline


def find_gcd(a, b):
    if b > a:
        return find_gcd(b, a)
    if b == 0:
        return a
    return find_gcd(b, a % b)


T = int(readline())
for _ in range(T):
    A, B, X = map(int, readline().split())
    gcd = find_gcd(A, B)
    print(X // gcd)
