import sys

readline = sys.stdin.readline

position = {'R': 0, 'G': 1, 'B': 2}
ccc = [(0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), (2, 1, 0)]

for _ in range(int(readline())):
    Nx, Ny, Nz = map(int, readline().split())
    S = ''
    cases = []
    for lineIdx in range(3):
        S = 'X' + readline().strip() + 'Z'
        subList = []
        cnt = {'X': 0, 'R': 0, 'G': 0, 'B': 0, 'Z': 0}

        subCh, subLen = S[0], 1
        for ch in S[1:]:
            if subCh != ch:
                subList.append((subCh, subLen))
                cnt[subCh] += subLen - 1
                subLen = 1
                subCh = ch
                continue
            subLen += 1
        subList.append(('Z', 1))
        # print(subList)

        case = {(cnt['R'], cnt['G'], cnt['B'])}
        tt = [cnt['R'], cnt['G'], cnt['B']]
        for i, (ch, ln) in enumerate(subList):
            if i == 0 or i == len(subList) - 1:
                continue
            preCh, nxtCh = subList[i - 1][0], subList[i + 1][0]
            k = 1 if ln != 1 else 0

            if ln == 1 and preCh == nxtCh:
                tt[position[preCh]] += 2
                case.add((tt[0], tt[1], tt[2]))
                tt[position[preCh]] -= 2
                continue

            tt[position[ch]] -= k
            if preCh != 'X':
                tt[position[preCh]] += 1
                case.add((tt[0], tt[1], tt[2]))
                tt[position[preCh]] -= 1
            if nxtCh != 'Z':
                tt[position[nxtCh]] += 1
                case.add((tt[0], tt[1], tt[2]))
                tt[position[nxtCh]] -= 1
            tt[position[ch]] += k
        # print(case)

        cases.append(case)
    mx = 0
    for caseA in cases[0]:
        for caseB in cases[1]:
            for caseC in cases[2]:
                pp = 0
                for cc in ccc:
                    pp += caseA[cc[0]] * caseB[cc[1]] * caseC[cc[2]]
                mx = max(mx, pp)
    print(mx)
