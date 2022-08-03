import sys
from math import ceil, log2

readline = sys.stdin.readline


class SegTree:
    def __init__(self, arr):
        self.arr = arr
        self.arrLen = len(arr)
        self.tree = [0] * (2 ** (ceil(log2(self.arrLen)) + 1))
        self.__segInit(1, 0, self.arrLen - 1)

    def __segInit(self, node, st, en):
        if st == en:
            self.tree[node] = self.arr[st]
        else:
            self.tree[node] = self.__segInit(node * 2, st, (st + en) // 2) + \
                              self.__segInit(node * 2 + 1, (st + en) // 2 + 1, en)
        return self.tree[node]

    def sum(self, left, right):
        return self.__segSum(1, 0, self.arrLen - 1, left, right)

    def __segSum(self, node, st, en, left, right):
        if left > en or right < st:
            return 0

        if left <= st and en <= right:
            return self.tree[node]

        return self.__segSum(node * 2, st, (st + en) // 2, left, right) + \
               self.__segSum(node * 2 + 1, (st + en) // 2 + 1, en, left, right)

    def update(self, idx, diff):
        return self.__segUpdate(1, 0, self.arrLen - 1, idx, diff)

    def __segUpdate(self, node, st, en, idx, diff):
        if idx < st or idx > en: return
        self.tree[node] += diff
        if st != en:
            self.__segUpdate(node * 2, st, (st + en) // 2, idx, diff)
            self.__segUpdate(node * 2 + 1, (st + en) // 2 + 1, en, idx, diff)


N, M, K = map(int, readline().split())
nums = [int(readline()) for _ in range(N)]

segTree = SegTree(nums)
for _ in range(M + K):
    a, b, c = map(int, readline().split())

    if a == 1:
        b -= 1
        df = c - nums[b]
        nums[b] = c
        segTree.update(b, df)
    elif a == 2:
        print(segTree.sum(b - 1, c - 1))
