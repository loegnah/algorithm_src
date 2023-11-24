import sys

readline = sys.stdin.readline


def solve(formula: list[str]):
    stack, k = [], 1
    ans, pre = 0, 0
    for i, f in enumerate(formula):
        if f == '+' or f == '-':
            stack.append(int(formula[pre:i]))
            pre = i + 1
        if f == '-':
            ans += (k * sum(stack))
            stack, k = [], -1
    stack.append(int(formula[pre:]))
    ans += (k * sum(stack))
    return ans


def main():
    formula = readline().strip()
    print(solve(formula))


main()
