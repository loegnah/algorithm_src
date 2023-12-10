# solve 2
import sys

readline = sys.stdin.readline

N = int(readline())
M = int(readline())
S = readline().rstrip() + 'OO'
target, targetLength = "I" + "OI" * N, N * 2 + 1
st, ans = 0, 0

while True:
    k = S.find(target, st)
    if k == -1:
        break
    length, en = 1, k + targetLength - 1
    while en < M:
        if S[en + 1:en + 3] == 'OI':
            en += 2
            length += 1
        else:
            break
    ans += length
    st = en
print(ans)

'''
# solve 1
import sys

readline = sys.stdin.readline

N = int(readline())
M = int(readline())
S = readline().rstrip() + 'OO'
i, ans = 0, 0

while i < M:
    if S[i] == 'I':
        length = 0
        while i < M:
            if S[i + 1:i + 3] == 'OI':
                i += 2
                length += 1
            else:
                break
        count = length - N + 1
        if count > 0:
            ans += count
    i += 1

print(ans)
'''
