import sys
import math

readline = sys.stdin.readline

def build_sparse_min(arr):
    n = len(arr)
    if n == 0:
        return []
    LOG = max(1, n.bit_length())
    table = [arr[:]]
    for k in range(1, LOG):
        prev = table[k - 1]
        half = 1 << (k - 1)
        row = []
        for i in range(n - (1 << k) + 1):
            row.append(min(prev[i], prev[i + half]))
        table.append(row)
    return table


def build_sparse_max(arr):
    n = len(arr)
    if n == 0:
        return []
    LOG = max(1, n.bit_length())
    table = [arr[:]]
    for k in range(1, LOG):
        prev = table[k - 1]
        half = 1 << (k - 1)
        row = []
        for i in range(n - (1 << k) + 1):
            row.append(max(prev[i], prev[i + half]))
        table.append(row)
    return table


def query_min(table, l, r):
    if l > r:
        return float('inf')
    length = r - l + 1
    k = length.bit_length() - 1
    return min(table[k][l], table[k][r - (1 << k) + 1])


def query_max(table, l, r):
    if l > r:
        return float('-inf')
    length = r - l + 1
    k = length.bit_length() - 1
    return max(table[k][l], table[k][r - (1 << k) + 1])


def solve(N, A):
    if N <= 1:
        return 0

    # monotone stack: left boundary where A[i] is max
    # left[i]: leftmost index such that A[i] is the max in [left[i], i]
    # strictly greater on left side
    left = [0] * N
    stack = []
    for i in range(N):
        while stack and A[stack[-1]] <= A[i]:
            stack.pop()
        left[i] = stack[-1] + 1 if stack else 0
        stack.append(i)

    # right[i]: rightmost index such that A[i] is the max in [i, right[i]]
    # strictly greater or equal on right side (to avoid double counting)
    right = [0] * N
    stack = []
    for i in range(N - 1, -1, -1):
        while stack and A[stack[-1]] < A[i]:
            stack.pop()
        right[i] = stack[-1] - 1 if stack else N - 1
        stack.append(i)

    # prefix sum: prefix[k] = A[0] + ... + A[k-1]
    prefix = [0] * (N + 1)
    for i in range(N):
        prefix[i + 1] = prefix[i] + A[i]

    # sparse tables on prefix array for range min/max
    sp_min = build_sparse_min(prefix)
    sp_max = build_sparse_max(prefix)

    ans = 0
    for i in range(N):
        li, ri = left[i], right[i]

        # left contribution: max(0, prefix[i] - min(prefix[li..i]))
        # sum(A[L..i-1]) = prefix[i] - prefix[L], maximize by minimizing prefix[L]
        # L ranges from li to i, so prefix[L] ranges over prefix[li..i]
        min_prefix_left = query_min(sp_min, li, i)
        left_contrib = prefix[i] - min_prefix_left

        # right contribution: max(0, max(prefix[i+1..ri+1]) - prefix[i+1])
        # sum(A[i+1..R]) = prefix[R+1] - prefix[i+1], maximize by maximizing prefix[R+1]
        # R ranges from i to ri, so R+1 ranges from i+1 to ri+1
        max_prefix_right = query_max(sp_max, i + 1, ri + 1)
        right_contrib = max_prefix_right - prefix[i + 1]

        total = left_contrib + right_contrib
        if total > ans:
            ans = total

    return ans


if __name__ == "__main__":
    N = int(readline())
    A = list(map(int, readline().split()))
    print(solve(N, A))
