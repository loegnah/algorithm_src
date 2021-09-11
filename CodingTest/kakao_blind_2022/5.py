def check(cur, wolfList, info, node, sheeps, wolfs):
    if not info[cur]:
        wolfs.append((wolfList[:], cur))
        
    if not node[cur]:
        return [] if info[cur] else [cur] 
    
    ret = []
    tmp = wolfList[:]
    if info[cur]:
        tmp.append(cur)
    for next in node[cur]:
        ret.extend(check(next, tmp, info, node, sheeps, wolfs))
        
    if info[cur]:
        sheeps[cur] = ret
    else:
        ret.append(cur)
    return ret

def comps(a):
    return len(a[0])

def solution(info, edges):
    prnt = [0] * len(info)
    node = [[] for _ in range(len(info))]
    sheeps = {}
    wolfs = []
    for a,b in edges:
        prnt[b] = a
        node[a].append(b)
    check(0, [], info, node, sheeps, wolfs)
    wolfs = sorted(wolfs, key=comps)
    
    wolfSet = set()
    sheepCnt = 1
    for prntWolfs, s in wolfs[1:]:
        newWolfCnt = 0
        for w in prntWolfs:
            if w not in wolfSet:
                newWolfCnt += 1
        if sheepCnt <= len(wolfSet) + newWolfCnt:
            continue
        sheepCnt += 1
        for w in prntWolfs:
            wolfSet.add(w)
        
    return sheepCnt