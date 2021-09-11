from collections import defaultdict
from typing import List

def solution(id_list: List, report: List, k: int):
    idMap = {}
    for i, id in enumerate(id_list):
        idMap[id] = i
    
    reported = defaultdict(set)
    for r in report:
        p, q = r.split()
        reported[q].add(idMap[p])

    answer = [0] * len(id_list)
        
    for rdList in reported.values():
        if len(rdList) >= k:
            for rd in rdList:
                answer[rd] += 1
        
    return answer