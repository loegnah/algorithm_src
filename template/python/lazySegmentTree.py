from math import ceil, log2


class LazySegTree:
    def __init__(self, arr):
        self.arr, self.arrLen = arr, len(arr)
        self.treeSize = 2 ** (ceil(log2(self.arrLen)) + 1)
        self.tree, self.lazy = [0] * self.treeSize, [0] * self.treeSize
        self.__segInit(1, 0, self.arrLen - 1)

    def __segInit(self, node, st, en):
        if st == en:
            self.tree[node] = self.arr[st]
        else:
            self.tree[node] = self.__segInit(node * 2, st, (st + en) // 2) + \
                              self.__segInit(node * 2 + 1, (st + en) // 2 + 1, en)
        return self.tree[node]

    def updateRange(self, left, right, diff):
        return self.__segUpdateRange(1, 0, self.arrLen - 1, left, right, diff)

    def __segUpdateRange(self, node, st, en, left, right, diff):
        self.__updateLazy(node, st, en)
        if right < st or left > en: return
        if left <= st and en <= right:
            self.tree[node] += (en - st + 1) * diff
            if st != en:
                self.lazy[node * 2] += diff
                self.lazy[node * 2 + 1] += diff
            return

        self.__segUpdateRange(node * 2, st, (st + en) // 2, left, right, diff)
        self.__segUpdateRange(node * 2 + 1, (st + en) // 2 + 1, en, left, right, diff)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

    def __updateLazy(self, node, st, en):
        if self.lazy[node] == 0: return

        self.tree[node] += (en - st + 1) * self.lazy[node]
        if st != en:
            self.lazy[node * 2] += self.lazy[node]
            self.lazy[node * 2 + 1] += self.lazy[node]
        self.lazy[node] = 0

    def sum(self, left, right):
        return self.__segSum(1, 0, self.arrLen - 1, left, right)

    def __segSum(self, node, st, en, left, right):
        self.__updateLazy(node, st, en)
        if left > en or right < st:
            return 0

        if left <= st and en <= right:
            return self.tree[node]

        return self.__segSum(node * 2, st, (st + en) // 2, left, right) + \
               self.__segSum(node * 2 + 1, (st + en) // 2 + 1, en, left, right)


# use
segTree = LazySegTree([1, 2, 3, 4, 5])
segTree.updateRange(0, 2, 2)
print(segTree.sum(0, 4))
