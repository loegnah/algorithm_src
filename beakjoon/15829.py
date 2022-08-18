from sys import stdin

readline = stdin.readline
r, M = 31, 1234567891
L = int(readline())

ans = 0
for i, ch in enumerate(readline().rstrip()):
    ai = ord(ch) - 96
    ans = (ans + (ai * pow(r, i, mod=M))) % M
print(ans)
