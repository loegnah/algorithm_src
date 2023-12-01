import sys
from math import sqrt
import bisect

readline = sys.stdin.readline
write = sys.stdout.write


def finePrimes(k: int):
    global primes, isPrime
    sqrtK = int(sqrt(k)) + 1
    isPrime[0], isPrime[1] = False, False
    for i in range(2, sqrtK + 1):
        if isPrime[i]:
            for j in range(i + i, k + 1, i):
                isPrime[j] = False
    for i in range(2, k + 1):
        if isPrime[i]:
            primes.append(i)
    return primes


def solve():
    global primes
    n = int(readline().strip())
    leftMaxIdx = bisect.bisect_right(primes, n // 2) - 1
    for lfIdx in range(leftMaxIdx, -1, -1):
        lf = primes[lfIdx]
        if isPrime[n - lf]:
            return lf, n - lf
    return -1, -1


maxN = 10000
primes = []
isPrime = [True] * (maxN + 1)
finePrimes(maxN)

T = int(readline().strip())
for _ in range(T):
    write(" ".join(map(str, solve())) + '\n')
