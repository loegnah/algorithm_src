def fwSum(fwTree, idx):
    ret = 0
    while idx > 0:
        ret += fwTree[idx]
        idx -= (idx & -idx)
    return ret


def fwUpdate(fwTree, idx, diff):
    while idx < len(fwTree):
        fwTree[idx] += diff
        idx += (idx & -idx)


nums = [1, 2, 3, 4, 5]
tree = [0] * (len(nums) + 1)

# init
for i, n in enumerate(nums):
    fwUpdate(tree, i + 1, n)
