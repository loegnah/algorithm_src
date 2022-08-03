from statistics import median
from collections import Counter
import sys

class Solve:
    def __init__(self):
        self.N = int(input())
        ssr = sys.stdin.readline
        self.nums = [int(ssr()) for _ in range(self.N)]
    
    def solve(self):
        print(round(sum(self.nums)/self.N))
        print(median(self.nums))
        print(self.calc_ans3())
        print(max(self.nums)-min(self.nums))

    def calc_ans3(self):
        cnt_nums = Counter(self.nums)
        max_cnt = cnt_nums.most_common(1)[0][1]
        tmp = sorted(a for a,b in cnt_nums.items() if b==max_cnt)
        if len(tmp)>1: return tmp[1]
        else: return tmp[0]    

solve = Solve()
solve.solve()

