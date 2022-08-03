import sys
from collections import OrderedDict

class Solve:
    def __init__(self):
        self.N = int(sys.stdin.readline())
        self.strs = [sys.stdin.readline().rstrip() for _ in range(self.N)]
    
    def solve(self):
        self.strs = sorted(list(OrderedDict.fromkeys(self.strs)))
        self.strs.sort(key=lambda s:len(s))
        for s in self.strs:
            sys.stdout.write(s+'\n')
sol = Solve()
sol.solve()