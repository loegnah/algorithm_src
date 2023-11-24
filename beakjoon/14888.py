import sys

readline = sys.stdin.readline

N = int(readline())
nums = list(map(int, readline().split()))
op = list(map(int, readline().split()))
mx, mn = float('-inf'), float('inf')


def dfs(depth, total, plus, minus, multiply, divide):
    global mx, mn, N, nums
    if depth == N:
        mx = max(total, mx)
        mn = min(total, mn)
        return

    if plus:
        dfs(depth + 1, total + nums[depth], plus - 1, minus, multiply, divide)
    if minus:
        dfs(depth + 1, total - nums[depth], plus, minus - 1, multiply, divide)
    if multiply:
        dfs(depth + 1, total * nums[depth], plus, minus, multiply - 1, divide)
    if divide:
        dfs(depth + 1, int(total / nums[depth]), plus, minus, multiply, divide - 1)


dfs(1, nums[0], op[0], op[1], op[2], op[3])
print(mx)
print(mn)
