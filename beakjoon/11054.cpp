// 11054.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const bool UP = false;
const bool DW = true;

int N;
int A[1003];
int cache[1003][1003][2];

int dp(int k, int pre, int state) {
	if (k >= N) return 0;
	int &ret = cache[k][pre][state];
	if (ret != -1) return ret;

	int cur = A[k];
	++k;
	if (cur == pre) ret = dp(k, pre, state);
	else if (state == DW) {
		if (pre < cur) ret = dp(k, pre, state);
		else ret = max(1+dp(k, cur, state), dp(k,pre,state));
	}
	else {
		ret = max(dp(k, pre, state), 1 + dp(k, cur, pre > cur));
	}
	return ret;
}

int main()
{
	memset(cache, -1, sizeof cache);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	printf("%d\n", dp(0, 0, UP));
}

