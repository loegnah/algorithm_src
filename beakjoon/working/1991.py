import sys
DOT = '.'

def preOrder(tree, curNode):
    ret = curNode
    if(tree[curNode][0] != DOT): ret += preOrder(tree,tree[curNode][0])
    if(tree[curNode][1] != DOT): ret += preOrder(tree,tree[curNode][1])
    return ret


def inOrder(tree, curNode):
    ret = ""
    if(tree[curNode][0] != DOT): ret += inOrder(tree,tree[curNode][0])
    ret += curNode
    if(tree[curNode][1] != DOT): ret += inOrder(tree,tree[curNode][1])
    return ret


def postOrder(tree, curNode):
    ret = ""
    if(tree[curNode][0] != DOT): ret += postOrder(tree,tree[curNode][0])
    if(tree[curNode][1] != DOT): ret += postOrder(tree,tree[curNode][1])
    ret += curNode
    return ret


n = int(sys.stdin.readline())
tree = dict()
for _ in range(n):
    a,b,c = sys.stdin.readline().split()
    tree[a] = (b,c)

print(preOrder(tree,'A'))
print(inOrder(tree,'A'))
print(postOrder(tree,'A'))
