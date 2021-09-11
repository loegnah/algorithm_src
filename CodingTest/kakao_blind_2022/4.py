def makeAllPossible(a):
    ret = []
    for i in range(a):
        ba = bin(i)[2:]
        ret.append(list('0'*(11-len(ba)) + ba))
    return ret
        
def solution(n, info):
    minWinShoot = [i+1 for i in info]
    score = [(10-i)*2 if info[i] else 10-i for i in range(11)]
    bScore = sum([(10-i) for i in range(11) if info[i]])
    allPossible = makeAllPossible(2048)
    maxScore = -1
    maxCase = []
    for caseI, wins in enumerate(allPossible):
        aScore = 0
        shoot = 0
        for i, win in enumerate(wins):
            if win == '1':
                shoot += minWinShoot[i]
                aScore += score[i]
        if shoot <= n and maxScore <= aScore:
            if maxScore < aScore:
                maxCase.clear()
            maxScore = aScore
            maxCase.append((n-shoot, caseI))
    if maxScore <= bScore:
        return [-1]
    bestCases = []
    for rmn, i in maxCase:
        goodPossible = allPossible[i]
        bestCase = [a if goodPossible[i]=='1' else 0 for i, a in enumerate(minWinShoot)]
        bestCase[-1] = rmn
        bestCases.append(bestCase[::-1])
        
    bestCases.sort()
    return list(reversed(bestCases[-1]))


n = [5,1,9,10]
info = [[2,1,1,1,0,0,0,0,0,0,0], [1,0,0,0,0,0,0,0,0,0,0],
        [0,0,1,2,0,1,1,1,1,1,1], [0,0,0,0,0,0,0,0,3,4,3]]

for i in range(len(n)):
    print(solution(n[i],info[i]))