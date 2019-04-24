OPEN = '('
CLOSE = ')'

T = int(input())

for _ in range(T):
    ipt = input()
    count = 0
    ans = True

    for ch in ipt:
        if ch==OPEN:
            count += 1
        elif count<=0:
            ans = False
            break
        else:
            count -= 1
    if count>0:
        ans = False
    
    if ans: print('YES')
    else: print('NO')
            