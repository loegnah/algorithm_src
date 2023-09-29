import sys

readline = sys.stdin.readline


def calc(stt, ln):
    end = stt + ln - 1
    if end < 3:
        return 0
    rIdx = stt - 1 if stt >= 3 else 2
    return end * (end + 1) // 2 - rIdx * (rIdx + 1) // 2


def check(k, kIdx, kSameLen):
    global stack
    ret = 0
    for tt in range(1, kSameLen + 1):
        ret += calc(1, tt)
    while stack and stack[-1][0] < k:
        s, sIdx, sSameLen = stack.pop()
        sIdxEnd = sIdx + sSameLen - 1
        ret += calc(kIdx - sIdxEnd + 1, sSameLen)

    if not stack:
        stack.append((k, kIdx, kSameLen))
        return ret

    if stack[-1][0] > k:
        s, sIdx, sSameLen = stack[-1]
        sIdxEnd = sIdx + sSameLen - 1
        ret += calc(kIdx - sIdxEnd + 1, kSameLen)
    elif stack[-1][0] == k:
        for j in range(kSameLen):
            for ii in range(len(stack) - 1, -1, -1):
                s, sIdx, sSameLen = stack[ii]
                sIdxEnd = sIdx + sSameLen - 1
                if s != k:
                    break
                ret += calc(kIdx + j - sIdxEnd + 1, sSameLen)
    stack.append((k, kIdx, kSameLen))
    return ret


T = int(readline())
for _ in range(T):
    N = int(readline())
    B = list(map(int, readline().split()))
    stack = []
    idx = 0
    ans = 0

    while idx < N:
        v = B[idx]
        sameLen = 1
        while idx + sameLen < N and B[idx + sameLen] == v:
            sameLen += 1
        # ans += check(v, idx, sameLen)
        aa = check(v, idx, sameLen)
        ans += aa
        idx += sameLen

    print(ans)
