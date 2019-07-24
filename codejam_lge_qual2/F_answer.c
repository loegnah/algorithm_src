#include <stdio.h>
#include <stdlib.h>
 
static void *objs[10000000];
static int objidx;
 
#define newt(t, n) ({ void *__t = calloc((n), sizeof(t)); objs[objidx++] = __t; __t;  })
#define new(n) ({ void *__t = calloc((n), 1); objs[objidx++] = __t; __t;  })
#define clean() do { while (objidx--) free(objs[objidx]); objidx = 0;  } while (0)
 
// Add a value from root to the leaf
static void add_seg(int *seg, int size, int idx, int val)
{
    int pow2 = 1;
    int base = 0;
    int divisor = (size + 1) / 2;
    int off;
    while (base < size) {
        off = idx / divisor;
        seg[base + off] += val;
        base += pow2;
        pow2 *= 2;
        divisor /= 2;
    }
}
 
// Find index corresponding to 'pos'
static void find_idx_seg(int *seg, int size, int pos, int *idx, int *remain)
{
    int pow2 = 2;
    int base = 1;
    int off = 0;
    while (base < size) {
        off *= 2;
        if (seg[base + off] < pos) {
            pos -= seg[base + off];
            off += 1;
        }
        base += pow2;
        pow2 *= 2;
    }
    *idx = off;
    *remain = pos - 1;
}
 
// Initialize the segment tree
static void init_seg(int *seg, int size, int n)
{
    int i, pow2, child, base;
 
    // Initialize the leaves first
    for (i = 0; i < n; i++)
        seg[(size + 1) / 2 - 1 + i] = 1;
 
    // Initialize the remains
    pow2 = (size + 1) / 4;
    while (pow2) {
        base = pow2 - 1;
        for (i = 0; i < pow2; i++) {
            child = (base + i) * 2 + 1;
            seg[base + i] = seg[child]+ seg[child + 1];
        }
        pow2 /= 2;
    }
}
 
struct node {
    char *d;
    struct node **c;
    struct node *p;
    int pidx;
    int *s;
    int n;
    int segn;
};
 
static int upper(int v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}
 
// Initialize a node
static void init_node(struct node *node, int n, char *data)
{
    node->d = data;
    node->c = newt(void *, n);
    node->p = 0;
    node->pidx = 0;
    node->n = n;
 
    // Determine size of the segment tree
    node->segn = upper(n) * 2 - 1;
    node->s = newt(int, node->segn);
 
    // Initialize the segment tree
    init_seg(node->s, node->segn, n);
}
 
// Find node and index corresponding to 'pos'
static void find_node(struct node *node, int pos, struct node **retn, int *reti)
{
    int idx;
    while (node) {
        find_idx_seg(node->s, node->segn, pos, &idx, &pos);
        if (!pos) {
            *retn = node;
            *reti = idx;
            return;
        }
        node = node->c[idx];
    }
 
    // This would never happens
    *retn = 0;
    *reti = 0;
}
 
// Fill the buffer walking trees from ('node', 'idx')
static void walk_node(char *buf, struct node *node, int idx, int remain, int inv)
{
    char val;
    while (1) {
        if (idx == -1)
            idx = node->n - 1;
 
        // Fill the buffer
        val = node->d[idx];
        if (inv)
            val = '0' + (int)!(val - '0');
        buf[--remain] = val;
 
        // Condition to stop
        if (!remain)
            break;
 
        // Advance the index backward
        if (--idx == -1) {
            idx = node->pidx;
            node = node->p;
            continue;
        }
        while (node->c[idx]) {
            node = node->c[idx];
            idx = node->n -1;
        }
    }
}
 
// Insert a new node to its parent
static void ins_node(struct node *node, int idx, struct node *new_node)
{
    int new_len = new_node->n;
    struct node *child;
 
    // If the parent already has a child, make it new_node's
    if (node->c[idx]) {
        child = node->c[idx];
        child->p = new_node;
        child->pidx = new_len - 1;
        new_node->c[new_node->n - 1] = child;
        add_seg(new_node->s, new_node->segn, new_len - 1, child->s[0]);
    }
 
    // Connect the child to the parent
    new_node->p = node;
    new_node->pidx = idx;
    node->c[idx] = new_node;
 
    // Propagate the new value over the whole tree
    while (node) {
        add_seg(node->s, node->segn, idx, new_len);
        idx = node->pidx;
        node = node->p;
    }
}
 
#define loop(i, n) for ((i) = 0; (i) < (n); (i)++)
#define back(i, n) for ((i) = (n) - 1; (i) >= 0; (i)--)
#define min(a, b) ((a) > (b) ? (b) : (a))
 
struct ops {
    int s;
    int e;
    int l;
};
 
int main(void)
{
    int i, j, n, m, k, tc, dist, boundary, idx, opscnt, walkidx;
    struct node *parent, *child, *node, *walknode;
    char *buf;
    struct node *root;
    struct ops *tmp_ops, *ops;
 
    scanf("%d", &tc);
    loop (i, tc) {
        root = newt(struct node, 1);
        scanf("%d %d %d", &n, &m, &k);
        buf = new(n + 1);
        scanf("%s", buf);
 
        // Get all operations
        tmp_ops = newt(struct ops, m);
        loop (j, m) {
            int s, e;
            scanf("%d %d", &s, &e);
            tmp_ops[j].s = s - 1;
            tmp_ops[j].e = e - 1;
        }
 
        // Select operations we're interested in
        ops = newt(struct ops, m);
        boundary = k - 1;
        opscnt = 0;
        back (j, m) {
            if (tmp_ops[j].e < boundary) {
                int l;
                l = tmp_ops[j].e - tmp_ops[j].s + 1;
                l = min(l, boundary - tmp_ops[j].e);
                boundary -= l;
                ops[opscnt] = tmp_ops[j];
                ops[opscnt++].l = l;
            }
        }
        m = opscnt;
 
        // Initialize the root node
        buf[boundary + 1] = '\0';
        init_node(root, boundary + 1, buf);
 
        // Apply operations one by one
        back (j, m) {
            int s = ops[j].s;
            int e = ops[j].e;
            int l = ops[j].l;
            dist = e - s + 1;
 
            // Locate where the child will be inserted to
            find_node(root, e + 1, &parent, &idx);
 
            // Locate where the walk starts from
            find_node(root, s + l, &walknode, &walkidx);
 
            // Create the child
            buf = new(l + 1);
            walk_node(buf, walknode, walkidx, l, 1);
            child = newt(struct node, 1);
            init_node(child, l, buf);
 
            // Connect the child to the parent
            ins_node(parent, idx, child);
        }
 
        // Print the first k elements
        buf = new(k + 1);
        find_node(root, k, &node, &idx);
        walk_node(buf, node, idx, k, 0);
        printf("%s\n", buf);
        clean();
    }
    return 0;
}