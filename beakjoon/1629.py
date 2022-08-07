import sys


def mult(k):
    if k == 1: return A % MOD
    ret = A if k % 2 else 1
    return ret * (pow(mult(k // 2), 2) % MOD) % MOD


A, B, MOD = map(int, sys.stdin.readline().split())
print(mult(B))
