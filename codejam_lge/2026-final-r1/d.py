import sys

readline = sys.stdin.readline


def sparse(arr, op):
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
            row.append(op(prev[i], prev[i + half]))
        table.append(row)
    return table


def query(table, l, r, op, default):
    if l > r:
        return default
    length = r - l + 1
    k = length.bit_length() - 1
    return op(table[k][l], table[k][r - (1 << k) + 1])


def solve(N, A):
    if N <= 1:
        return 0

    left = [0] * N
    stack = []
    for i in range(N):
        while stack and A[stack[-1]] <= A[i]:
            stack.pop()
        left[i] = stack[-1] + 1 if stack else 0
        stack.append(i)

    right = [0] * N
    stack = []
    for i in range(N - 1, -1, -1):
        while stack and A[stack[-1]] < A[i]:
            stack.pop()
        right[i] = stack[-1] - 1 if stack else N - 1
        stack.append(i)

    prefix = [0] * (N + 1)
    for i in range(N):
        prefix[i + 1] = prefix[i] + A[i]

    sp_min = sparse(prefix, min)
    sp_max = sparse(prefix, max)

    ans = 0
    for i in range(N):
        li, ri = left[i], right[i]

        min_prefix_left = query(sp_min, li, i, min, float('inf'))
        left_contrib = prefix[i] - min_prefix_left

        max_prefix_right = query(sp_max, i + 1, ri + 1, max, float('-inf'))
        right_contrib = max_prefix_right - prefix[i + 1]

        total = left_contrib + right_contrib
        if total > ans:
            ans = total

    return ans


if __name__ == "__main__":
    N = int(readline())
    A = list(map(int, readline().split()))
    print(solve(N, A))
