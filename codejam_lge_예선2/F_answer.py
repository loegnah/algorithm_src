import sys
 
# Add a value from root to the leaf
def add_seg(seg, idx, val):
    size = len(seg)
    pow2 = 1
    base = 0
    divisor = (size + 1) // 2
    while base < size:
        off = idx // divisor
        seg[base + off] += val
        base += pow2
        pow2 *= 2
        divisor //= 2
 
 
# Find index corresponding to 'pos'
def find_idx_seg(seg, pos):
    size = len(seg)
    pow2 = 2
    base = 1
    off = 0
    while base < size:
        off *= 2
        if seg[base + off] < pos:
            pos -= seg[base + off]
            off += 1
        base += pow2
        pow2 *= 2
    return off, pos - 1
 
 
# Initialize the segment tree
def init_seg(seg, n):
    size = len(seg)
 
    # Initialize the leaves first
    for i in range(n):
        seg[(size + 1) // 2 - 1 + i] = 1
 
    # Initialize the remains
    pow2 = (size + 1) // 4
    while pow2:
        base = pow2 - 1
        for i in range(pow2):
            child = (base + i) * 2 + 1
            seg[base + i] = seg[child] + seg[child + 1]
        pow2 //= 2
 
 
# Initialize a node
def init_node(node, n, data):
    node['d'] = data
    node['c'] = [None] * n
    node['p'] = (None, None)
 
    # Determine size of the segment tree
    aligned = 1 << (n.bit_length() - 1)
    size = aligned * (2 if aligned == n else 4) - 1
    node['s'] = [0] * size
 
    # Initialize the segement tree
    init_seg(node['s'], n)
 
 
# Find node and index corresponding to 'pos'
def find_node(node, pos):
    while node:
        idx, pos = find_idx_seg(node['s'], pos)
        if not pos:
            return node, idx
        node = node['c'][idx]
 
    # This would never happens
    return None, None
 
 
# Fill the buffer walking trees from ('node', 'idx')
def walk_node(buf, node, idx, remain, inv):
    while True:
        if idx == -1:
            idx = len(node['d']) - 1
 
        # Fill the buffer
        val = node['d'][idx]
        if inv:
            val = '0' if val == '1' else '1'
        buf[remain - 1] = val
        remain -= 1
 
        # Condition to stop
        if not remain:
            break
 
        # Advance the index backward
        idx -= 1
        if idx == -1:
            # Goto its parent
            node, idx = node['p']
            continue
        while node['c'][idx]:
            # Goto its child
            node, idx = node['c'][idx], -1
 
 
# Insert a new node to its parent
def ins_node(node, idx, new_node):
    new_len = len(new_node['d'])
 
    # If the parent already has a child, make it new_node's
    if node['c'][idx]:
        child = node['c'][idx]
        child['p'] = (new_node, new_len - 1)
        new_node['c'][-1] = child
        add_seg(new_node['s'], new_len - 1, child['s'][0])
 
    # Connect the child to the parent
    new_node['p'] = (node, idx)
    node['c'][idx] = new_node
 
    # Propagate the new value over the whole tree
    while node:
        add_seg(node['s'], idx, new_len)
        node, idx = node['p']
 
 
# Main
for i in range(int(sys.stdin.readline())):
    n, m, k = (int(j) for j in sys.stdin.readline().split())
    str = sys.stdin.readline()
 
    # Get all operations
    tmp_ops = list()
    for j in range(m):
        op = tuple(int(k) - 1 for k in sys.stdin.readline().split())
        tmp_ops.append(op)
 
    # Select operations we're interested in
    ops = list()
    boundary = k - 1
    for j in range(m - 1, -1, -1):
        if tmp_ops[j][1] < boundary:
            l = tmp_ops[j][1] - tmp_ops[j][0] + 1
            l = min(l, boundary - tmp_ops[j][1])
            boundary -= l
            ops.append((tmp_ops[j][0], tmp_ops[j][1], l))
    m = len(ops)
 
    # Initialize the root node
    root = dict()
    init_node(root, boundary + 1, list(str[:boundary + 1]))
 
    # Apply operations one by one
    for j in range(m - 1, -1, -1):
        s, e, l = ops[j]
        dist = e - s + 1
 
        # Locate where the child will be inserted to
        parent, idx = find_node(root, e + 1)
 
        # Locate where the walk starts from
        walknode, walkidx = find_node(root, s + l)
 
        # Create the child
        buf = [0] * l
        walk_node(buf, walknode, walkidx, l, True)
        child = dict()
        init_node(child, l, buf)
 
        # Connect the child to the parent
        ins_node(parent, idx, child)
 
    # Print the first k elements
    buf = [0] * k
    node, idx = find_node(root, k)
    walk_node(buf, node, idx, k, False)
    for j in range(k):
        sys.stdout.write(buf[j])
    sys.stdout.write('\n')