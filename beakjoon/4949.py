import sys

readline = sys.stdin.readline

while True:
    line = readline().rstrip()
    if line == '.':
        break

    stack = []
    ans = 'yes'
    for ch in line:
        if ch == '(' or ch == '[':
            stack.append(ch)
        elif ch == ')':
            if not stack or stack[-1] != '(':
                ans = 'no'
                break
            else:
                stack.pop()
        elif ch == ']':
            if not stack or stack[-1] != '[':
                ans = 'no'
                break
            else:
                stack.pop()
    if stack:
        ans = 'no'
    print(ans)
