import sys

readline = sys.stdin.readline

ALL_CASE = [(0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), (2, 1, 0)]

for _ in range(int(readline())):
    readline()
    cases_per_line = []
    for lineIdx in range(3):
        S = readline().strip()
        subList = []
        cnt = {'R': 0, 'G': 0, 'B': 0}

        subCh, subLen = 'X', 0
        for ch in S:
            if subCh == ch:
                subLen += 1
                continue
            if subCh != 'X':
                subList.append((subCh, subLen))
                cnt[subCh] += subLen - 1
            subCh, subLen = ch, 1

        subList.append((subCh, subLen))
        cnt[subCh] += subLen - 1
        # print(subList)

        case = {(cnt['R'], cnt['G'], cnt['B'])}
        subListLen = len(subList)

        for i, (ch, ln) in enumerate(subList):
            preCh = subList[i - 1][0] if i > 0 else 'X'
            nxtCh = subList[i + 1][0] if i < subListLen - 1 else 'Z'
            k = 1 if ln != 1 else 0

            if ln == 1 and preCh == nxtCh:
                cnt[preCh] += 2
                case.add((cnt['R'], cnt['G'], cnt['B']))
                cnt[preCh] -= 2
                continue

            cnt[ch] -= k
            if preCh != 'X':
                cnt[preCh] += 1
                case.add((cnt['R'], cnt['G'], cnt['B']))
                cnt[preCh] -= 1
            if nxtCh != 'Z':
                cnt[nxtCh] += 1
                case.add((cnt['R'], cnt['G'], cnt['B']))
                cnt[nxtCh] -= 1
            cnt[ch] += k
        print(case)
        cases_per_line.append(case)

    mx_case = 0
    for case_line_one in cases_per_line[0]:
        for case_line_two in cases_per_line[1]:
            for case_line_three in cases_per_line[2]:
                cur_case = 0
                for CASE in ALL_CASE:
                    cur_case += case_line_one[CASE[0]] * case_line_two[CASE[1]] * case_line_three[CASE[2]]
                mx_case = max(mx_case, cur_case)
    print(mx_case)
