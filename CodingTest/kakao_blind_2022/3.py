from collections import defaultdict
import math

END = 1439

def convertToMin(s):
    h, m = s.split(':')
    return int(h)*60 + int(m)

def comp(a, b):
    return a

def solution(fees, records):
    carRecords = defaultdict(list)
    
    bT, bF, pT, pF = fees
    for record in records:
        time, num, cmd = record.split()
        carRecords[num].append(convertToMin(time))
    
    feeMap = {}
    for car, carRecord in carRecords.items():
        if len(carRecord) % 2:
            carRecord.append(END)
        timeSum = 0
        for i in range(0, len(carRecord), 2):
            timeSum += carRecord[i+1] - carRecord[i]
            
        feeSum = bF
        if timeSum > bT:
            feeSum += math.ceil((timeSum-bT)/pT) * pF
        feeMap[car] = feeSum
    
    answer = []
    for a in sorted(feeMap):
        answer.append(feeMap[a])
    return answer