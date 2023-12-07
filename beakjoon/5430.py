import sys

readline = sys.stdin.readline


def solve(funcs, nums):
    lf, rt = 0, len(nums) - 1
    idx = lf
    for f in funcs:
        if f == 'R':
            idx = rt if idx == lf else lf
        elif f == 'D':
            if lf > rt:
                return 'error'
            if idx == lf:
                lf = idx = idx + 1
            else:
                rt = idx = idx - 1
    ans = nums[lf:rt + 1] if idx == lf else nums[lf:rt + 1][::-1]
    return "[" + ",".join(ans) + "]"


def main():
    T = int(readline())
    for _ in range(T):
        funcs = readline().strip()
        _ = int(readline())
        a = readline().strip()[1:-1]
        nums = a.split(",") if len(a) else []
        print(solve(funcs, nums))


main()
