# D번 풀이 — 양보의 미덕 (50점)

## 난이도: Gold II

## 문제 요약

N개의 사탕이 일렬로 있고, 연속 구간 [L, R]을 골라서 가장 맛있는 사탕(최대값) 하나를 양보한 뒤,
나머지 합 `sum(A[L..R]) - max(A[L..R])`을 최대화하라.

## 알고리즘

### 핵심 관찰

`sum(A[L..R]) - max(A[L..R])`을 최대화하려면, 각 원소 A[i]가 구간의 최대값(양보 대상)이 되는
모든 경우를 고려한다.

A[i]가 구간 [L, R]의 최대값이 되려면, [L, R]이 A[i]가 최대인 범위 안에 있어야 한다.
이 범위를 monotone stack으로 구할 수 있다.

### 단계별 접근

#### 1단계: Monotone Stack으로 "최대인 범위" 구하기

각 i에 대해:
- `left[i]`: i 왼쪽에서 A[i]보다 **큰** 원소의 가장 가까운 위치 + 1 (없으면 0)
- `right[i]`: i 오른쪽에서 A[i] **이상**인 원소의 가장 가까운 위치 - 1 (없으면 N-1)

동일 값 중복 방지를 위해 한쪽은 strictly greater, 한쪽은 greater or equal.

범위 [left[i], right[i]] 내에서 A[i]가 최대값이 됨을 보장.

#### 2단계: Prefix Sum + Sparse Table (RMQ)

prefix[k] = A[0] + A[1] + ... + A[k-1] (prefix[0] = 0)

A[i]가 최대인 구간 [L, R] (L ≤ i ≤ R)에서:
- sum(A[L..R]) - A[i] = (sum(A[L..i-1])) + (sum(A[i+1..R]))
- = (prefix[i] - prefix[L]) + (prefix[R+1] - prefix[i+1])

왼쪽 기여 최대화: prefix[i] - min(prefix[left[i]..i])
오른쪽 기여 최대화: max(prefix[i+1..right[i]+1]) - prefix[i+1]

각각 0 이상 (빈 구간 선택 가능, 단 양쪽 다 비면 안 됨 — 최소 2개 원소 필요).

실제로는 양쪽 합이 음수면 길이 1 구간을 선택하여 답 0을 얻을 수 있으므로,
답의 하한은 0이다.

#### 3단계: 범위 min/max 쿼리

Sparse Table로 prefix의 범위 min, 범위 max를 O(1)에 응답.

전체 답 = max over all i of (left_contrib[i] + right_contrib[i])
단, max(답, 0)으로 하한 처리.

## 시간 복잡도

| 단계 | 복잡도 |
|------|--------|
| Monotone Stack | O(N) |
| Prefix Sum | O(N) |
| Sparse Table 구축 | O(N log N) |
| 각 i에서 답 후보 계산 | O(N) × O(1) = O(N) |
| **전체** | **O(N log N)** |

N = 200,000 기준 Python에서 충분히 빠르다.
