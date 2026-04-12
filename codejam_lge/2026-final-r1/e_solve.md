# E - Treasure Hunt (50pts)

## Difficulty: Diamond III

## Problem Summary

N×M grid (N,M ≤ 15) with contaminated (#) and clean (.) cells. Treasure is in exactly one cell.
- If treasure is in a contaminated cell: just need to determine that fact.
- If treasure is in a clean cell: need to find the exact position.

Probing cell (x,y) costs C[x][y]. If treasure is there, found immediately. Otherwise, adversary reveals one of 4 valid quadrant hints: (X≥x,Y≥y), (X≥x,Y≤y), (X≤x,Y≥y), (X≤x,Y≤y). On boundaries (X=x or Y=y), multiple hints may be valid and the adversary picks the worst for us.

Goal: minimize worst-case total probing cost to identify the treasure status.

## Key Observations

1. **Categories to distinguish**: Each clean cell is a unique category. All contaminated cells form one group. We're done when ≤1 category remains in the possible region.

2. **Rectangle state**: After receiving a quadrant hint, the possible region remains a rectangle. So the state is (x1, y1, x2, y2).

3. **Excluded points**: When we probe (x,y) and it's not there, (x,y) is excluded from future consideration. Since (x,y) is always a corner of every resulting quadrant, we must track excluded points to avoid self-referential DP (e.g., probing a corner of [x1..x2]×[y1..y2] yields one quadrant equal to the entire rectangle).

4. **Adversary picks worst quadrant**: After probing (x,y), the adversary effectively directs us to whichever of the 4 sub-rectangles has the highest future cost.

## Algorithm

**Minimax DP with memoization.**

State: `(x1, y1, x2, y2, excluded)` where excluded is a sorted tuple of encoded cell indices already probed and confirmed empty.

```
dp(rect, excluded) = 0                              if categories ≤ 1
                   = min over probes (x,y) of:
                       C[x][y] + max over 4 quadrants Q_k of:
                           dp(Q_k, filtered_excluded ∪ {(x,y)})
```

### Handling Self-Reference

When probing a corner (x1,y1) of the rectangle, quadrant Q1 = [x1..x2]×[y1..y2] equals the entire rectangle. Instead of infinite recursion, we pass (x,y) as an excluded point: `dp(rect, excluded ∪ {(x,y)})`. This reduces the number of categories by 1 (if (x,y) was a clean cell), eventually reaching the base case.

### Pruning

- Sort probes by cost ascending; break early when `cost ≥ best`.
- Evaluate quadrants and prune when `cost + worst_so_far ≥ best`.
- Precompute sorted probe orders for each rectangle.

## Complexity

- States: O(N²M² × |excluded variants|). In practice, excluded sets are small.
- Per state: O(NM) probe choices, each with O(|excluded|) filtering for 4 quadrants.
- Worst case (15×15 all clean, uniform cost): ~3 seconds in Python with pruning.

## Implementation Notes

- Encode cells as `x*M + y` for compact excluded tuples.
- Precompute `cell_row[]`, `cell_col[]`, `clean_flat[]` for fast lookups.
- Prefix sum array for O(1) rectangle clean-cell counting.
- Filter excluded to sub-rectangle when passing to recursive calls (improves cache hit rate).
