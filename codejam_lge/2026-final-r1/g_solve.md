# G - 트리 위의 사각형 (50pts)

## 난이도: Diamond III

## Problem Summary

루트가 1번인 이진 트리 $T$ (정점 $N \le 10^5$개, 각 정점에 $1 \le V_i \le M \le 50$). 서로 다른 네 정점의 순서쌍 $(a,b,c,d)$가 다음을 만족하는 개수를 $998244353$로 나눈 나머지로 구하라.

1. $a,b,c,d$가 서로 pairwise incomparable (어떤 둘도 조상-후손 관계가 아님).
2. $V_{\text{lca}(a,b)} = V_{\text{lca}(c,d)}$, $V_{\text{lca}(b,c)} = V_{\text{lca}(d,a)}$.

## Key Observations

### 1. LCA Structure (Split at root L)

$L = \text{lca}(a,b,c,d)$. $L$은 2개의 자식을 가진다 (binary tree + incomparable 4 nodes ⇒ 양쪽에 분포). 4개 노드가 $L$의 두 자식 subtree에 나눠지는 방식:
- **(2,2) split**: 각 자식 subtree에 2개씩.
- **(1,3) split**: 한쪽에 1개, 반대쪽에 3개.

### 2. Cycle View

$(a,b,c,d)$를 4-cycle로 보면 $X,Y,Z,W$는 그 변들이고, $(X,Y)$와 $(Z,W)$는 반대편 변쌍(opposite edge pair partition). 4개 원소의 pair partition은 3가지, cycle은 3가지이고 각 cycle은 서로 다른 2개의 partition을 반대쌍으로 가진다.

한 cycle에서 8개 ordering 모두가 조건 만족 ⟺ 그 cycle의 두 반대쌍 partition 각각이 "두 쌍의 LCA V값이 같음"을 만족.

### 3. Case A: (2,2) split at L

$L$의 자식 $c_1, c_2$. 한쪽에서 incomparable pair의 lca = $P$, 반대쪽에서 = $Q$.
- 3개 partition 중 하나는 "same-side" (lcas = $(P,Q)$), 나머지 둘은 "cross-side" (lcas = $(L,L)$).
- 매칭 조건이 모두 성립하는 cycle 개수: $V_P=V_Q$이면 3개 cycle 모두, 아니면 1개 (all cross).
- 따라서 ordered count: $V_P = V_Q$면 **24**, 아니면 **8**.

### 4. Case B: (1,3) split at L

$L$의 한 자식 subtree에 singleton $x_0$, 반대 자식 subtree에 3 nodes. 그 3 nodes의 lca가 $L'$, $L'$에서 split (1,2)에 의한 inner pair의 lca가 $L''$.

3 partition들의 lca 쌍:
- $\{(x_0,y_0),(u,v)\}$: lcas $(L, L'')$
- $\{(x_0,u),(y_0,v)\}$: lcas $(L, L')$  
- $\{(x_0,v),(y_0,u)\}$: lcas $(L, L')$

$\alpha = [V_L = V_{L'}]$, $\beta = [V_L = V_{L''}]$라 하면 ordered count $= 8\alpha(\alpha + 2\beta)$:
- $V_L \neq V_{L'}$: **0**
- $V_L = V_{L'}, V_L \neq V_{L''}$: **8**
- $V_L = V_{L'} = V_{L''}$: **24**

## Algorithm

각 노드 $v$에 대해 다음을 트리 DP로 계산:

- $\text{pair}(v, c)$: subtree($v$) 안에 lca가 $v$ 이하에 있으면서 V값이 $c$인 incomparable pair 수.
- $\text{tri\_total}(v)$: $v$가 2-child일 때 (singleton, pair) 구조의 총 수.
- $A(v, c) = \sum_{w \in \text{subtree}(v), V_w = c} \text{tri\_total}(w)$.
- $B(v, c) = \sum_{w \in \text{subtree}(v), V_w = c} \text{tri}(w, c)$ where $\text{tri}(w, c) = $ (singleton, pair with lca V = $c$) count at $w$.

### Recurrences

$v$ leaf: 모두 0.  
$v$ 1-child ($c$): $\text{pair}(v) = \text{pair}(c)$, $A(v) = A(c)$, $B(v) = B(c)$.  
$v$ 2-child ($d_1, d_2$):
- $\text{pair}(v, c) = \text{pair}(d_1, c) + \text{pair}(d_2, c) + [c = V_v] \cdot |d_1| \cdot |d_2|$
- $\text{tri}(v, c) = |d_1| \cdot \text{pair}(d_2, c) + |d_2| \cdot \text{pair}(d_1, c)$
- $\text{tri\_total}(v) = |d_1| P(d_2) + |d_2| P(d_1)$ where $P(v) = \sum_c \text{pair}(v,c)$
- $A(v, c) = A(d_1, c) + A(d_2, c) + [c = V_v] \cdot \text{tri\_total}(v)$
- $B(v, c) = B(d_1, c) + B(d_2, c) + [c = V_v] \cdot \text{tri}(v, V_v)$ (only $c = V_v$ term adds)

### Summation

$L$이 2-child이고 자식 $c_1, c_2$, $c_L = V_L$일 때:
- Case A: $8 \cdot P(c_1) P(c_2) + 16 \sum_c \text{pair}(c_1,c) \text{pair}(c_2,c)$
- Case B: $8(|c_1| A(c_2, c_L) + |c_2| A(c_1, c_L)) + 16(|c_1| B(c_2, c_L) + |c_2| B(c_1, c_L))$

Answer = $\sum_L (\text{Case A} + \text{Case B}) \mod 998244353$.

## Complexity

$O(N \cdot M) = O(5 \cdot 10^6)$. numpy 벡터화로 trees 순회.
