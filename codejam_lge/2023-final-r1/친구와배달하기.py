from sys import stdin

readline = stdin.readline

T = int(readline())
for _ in range(T):
    N, Pa, Pb = map(int, readline().split())
    positions = sorted(list(map(int, readline().split())))

    if Pa > Pb:
        Pa, Pb = Pb, Pa

    sumA, sumB = 0, (Pb * N - sum(positions))
    minDistSum = sumA + sumB
    minDif = abs(sumB - sumA)
    for i in range(N):
        sumA += positions[i] - Pa
        sumB -= Pb - positions[i]
        if minDistSum > sumA + sumB:
            minDistSum = sumA + sumB
            minDif = abs(sumB - sumA)
        elif minDistSum == sumA + sumB:
            minDif = min(minDif, abs(sumB - sumA))
    print(minDistSum * 2, minDif * 2)
