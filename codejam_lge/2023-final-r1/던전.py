from sys import stdin

readline = stdin.readline

EnergyMax = 2 ** 63
DamageMax = 10 ** 13

T = int(input())
for _ in range(T):
    N = int(input())
    D = list(map(int, readline().split()))
    cmd = readline().strip()
    R = list(map(int, readline().split()))

    lf, rt = 0, EnergyMax
    md = (lf + rt) // 2

    while lf < rt:
        energy = md

        for i in range(N):
            energy -= D[i]
            if energy <= 0: break
            if energy > DamageMax: break

            if cmd[i] == '+':
                energy += R[i]
            else:
                energy *= R[i]

        if energy <= 0:
            lf = md + 1
        else:
            rt = md
        md = (lf + rt) // 2

    print(md)
