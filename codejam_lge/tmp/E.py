import sys

readline = sys.stdin.readline
sys.setrecursionlimit(100500)


def visit(n):
    global ans_ln, ans_cnt, children, value
    cur_value = value[n]

    if not children[n]:
        return 1, cur_value

    children_rets = []
    for c in children[n]:
        ret = visit(c)
        check_ans(ret[0], 1)
        if value[c] != cur_value:
            children_rets.append(ret)

    if not children_rets:
        return 1, cur_value

    children_rets.sort(reverse=True)
    best_ln, best_v = children_rets[0]
    # check_ans(best_ln + 1, 1)

    if len(children_rets) >= 2:
        second_ln = children_rets[1][0]
        if best_ln == second_ln and ans_ln <= best_ln * 2 + 1:
            tot_ln = best_ln * 2 + 1
            cnt = 2
            for ln, v in children_rets[2:]:
                if ln != best_ln:
                    break
                cnt += 1
            tot_cnt = int(cnt * (cnt - 1) / 2)
            check_ans(tot_ln, tot_cnt)
        elif best_ln > second_ln and ans_ln <= best_ln + second_ln + 1:
            tot_ln = best_ln + second_ln + 1
            tot_cnt = 1
            for ln, v in children_rets[2:]:
                if ln != second_ln:
                    break
                tot_cnt += 1
            check_ans(tot_ln, tot_cnt)
    return best_ln + 1, cur_value


def check_ans(ln, cnt):
    global ans_ln, ans_cnt
    if ln > ans_ln:
        ans_ln, ans_cnt = ln, cnt
    elif ln == ans_ln:
        ans_cnt += cnt


T = int(readline())
ans_ln, ans_cnt = 0, 0
for _ in range(T):
    N = int(readline())
    children = [[] for _ in range(N + 1)]
    value = '0' + readline().strip()
    parents = list(map(int, readline().split()))
    ans_ln, ans_cnt = 0, 0
    root = 0
    for i, p in enumerate(parents):
        if p == 0:
            root = i + 1
        children[p].append(i + 1)

    visit(0)
    print(ans_ln, ans_cnt)
