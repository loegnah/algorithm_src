from math import ceil, log2
import sys

readline = sys.stdin.readline
write = sys.stdout.write


class LazySegTree:
    def __init__(self, arr):
        self.arr, self.arrLen = arr, len(arr)
        self.treeSize = 2 ** (ceil(log2(self.arrLen)) + 1)
        self.tree, self.lazy = [0] * self.treeSize, [0] * self.treeSize
        self.__init(1, 0, self.arrLen - 1)

    def __init(self, node, st, en):
        if st == en:
            self.tree[node] = self.arr[st]
        else:
            self.tree[node] = self.__init(node * 2, st, (st + en) // 2) + \
                              self.__init(node * 2 + 1, (st + en) // 2 + 1, en)
        return self.tree[node]asdfasdfdddddddddddd

    def toggleRange(self, left, right):
        return self.__toggleRangeImpl(1, 0, self.arrLen - 1, left, right)

    def __toggleRangeImpl(self, node, st, en, left, right):
        self._toggleLazy(node, st, en)
        if right < st or left > en: return
        if left <= st and en <= right:
            self.tree[node] = (en - st + 1) - self.tree[node]
            if st != en:
                self.lazy[node * 2] ^= 1
                self.lazy[node * 2 + 1] ^= 1
            return

        self.__toggleRangeImpl(node * 2, st, (st + en) // 2, left, right)
        self.__toggleRangeImpl(node * 2 + 1, (st + en) // 2 + 1, en, left, right)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

    def _toggleLazy(self, node, st, en):
        if self.lazy[node] == 0: return

        self.tree[node] = (en - st + 1) - self.tree[node]
        if st != en:
            self.lazy[node * 2] ^= 1
            self.lazy[node * 2 + 1] ^= 1
        self.lazy[node] = 0

    def sum(self, left, right):
        return self.__sumImpl(1, 0, self.arrLen - 1, left, right)

    def __sumImpl(self, node, st, en, left, right):
        self._toggleLazy(node, st, en)
        if left > en or right < st:
            return 0

        if left <= st and en <= right:
            return self.tree[node]

        return self.__sumImpl(node * 2, st, (st + en) // 2, left, right) + \
            self.__sumImpl(node * 2 + 1, (st + en) // 2 + 1, en, left, right)


N, M = map(int, readline().split())
lst = LazySegTree([0] * (N + 1))

for _ in range(M):
    cmd, s, t = map(int, readline().split())
    if cmd == 0:
        lst.toggleRange(s - 1, t - 1)
    elif cmd == 1:
        write(str(lst.sum(s - 1, t - 1)) + '\n')
