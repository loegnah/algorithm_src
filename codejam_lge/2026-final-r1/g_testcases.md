# G - Test Cases

## TC1: Example 1 (2-2 split, V_P = V_Q)

```
7 2
1 1 1 2 2 2 2
1 2
1 3
2 4
2 5
3 6
3 7
```

**Expected: 24**

트리 구조: 1(V=1) → {2(V=1)→{4,5(V=2)}, 3(V=1)→{6,7(V=2)}}. 유일한 4-incomparable set = {4,5,6,7}. L=1, (2,2) split, P=2 (V=1), Q=3 (V=1). V_P = V_Q = 1이므로 24 orderings 모두 유효.

## TC2: Example 2 (Mixed tree)

```
12 2
2 2 1 1 1 1 1 1 2 1 1 2
9 8
5 2
2 1
4 5
8 11
10 11
6 12
10 12
10 1
6 7
5 3
```

**Expected: 216**

복잡한 트리에서 Case A만 기여, V_1=2, c1=2(P=1, lca=5 V=1), c2=10(P=9, lca=10 V=1). V_P=V_Q=1.

## TC3: No incomparable 4-set

```
4 2
1 1 1 1
1 2
2 3
3 4
```

**Expected: 0**

체인 구조. pairwise incomparable 4개가 없음.

## TC4: 1-3 split with α=1, β=0 (contribution 8)

```
7 3
1 1 1 2 2 3 3
1 2
1 3
3 4
3 5
5 6
5 7
```

**Expected: 8**

트리: 1(V=1) → {2(V=1,leaf), 3(V=1)→{4(V=2,leaf), 5(V=2)→{6(V=3),7(V=3)}}}. 유일 4-set = {2,4,6,7}. L=1, singleton=2, triple에서 L'=3 (V=1), L''=5 (V=2). α=[V_L=V_L']=[1=1]=1, β=[V_L=V_L'']=[1=2]=0. Count = 8·1·(1+0) = 8.

## TC5: 1-3 split with α=1, β=1 (contribution 24)

```
7 1
1 1 1 1 1 1 1
1 2
1 3
3 4
3 5
5 6
5 7
```

**Expected: 24**

TC4와 동일한 구조, 모든 V=1. L=1, L'=3, L''=5 모두 V=1. α=β=1. Count = 8·1·(1+2) = 24.

## TC6: 2-2 split with V_P ≠ V_Q (contribution 8)

```
7 7
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
```

**Expected: 8**

Example 1 구조, 모든 V 서로 다름. 유일 4-set = {4,5,6,7}. (2,2) split at 1. P=2(V=2), Q=3(V=3). V_P ≠ V_Q이므로 8 orderings만 유효.

## TC7: Larger balanced tree (all same value)

```
15 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
```

**Expected: 4968**

완전 이진 트리 (15 nodes, 4 levels). 모든 V=1이므로 모든 pairwise incomparable 4-set이 24 orderings을 기여. Antichain of size 4 개수를 트리 DP로 셈: f(v, k) = # antichains of size k in subtree(v). 루트에서 f(1, 4) = 207. Total = 207 × 24 = 4968.

## TC8: Small tree N=4 with 2 leaves visible

```
5 2
1 1 1 2 2
1 2
1 3
2 4
2 5
```

**Expected: 0**

트리: 1→{2→{4,5}, 3(leaf)}. Incomparable 최대: {3,4,5}, 3개뿐. 4개 pairwise incomparable 불가.
