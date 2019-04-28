#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int tower[100001];
int L[100002], R[100002];

int main(void)
{
	setbuf(stdout, NULL);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d", &N);
		for (int n = 1; n <= N; ++n)
			scanf("%d", tower + n);
		L[0] = R[N+1] = 0;
		

// The kill time for each tower is the kill time + 1 of the towers directly beside it.
		for (int left = 1; left <= N; ++left)
			L[left] = min(L[left - 1] + 1, tower[left]);
		for (int right = N; right > 0; --right)
			R[right] = min(R[right + 1] + 1, tower[right]);
		
		int mxRmvTm = 0;
		for (int n = 1; n <= N; ++n)
			mxRmvTm = max(mxRmvTm, min(R[n], L[n]));
		printf("Case #%d\n", t+1);
		printf("%d\n", mxRmvTm);
	}

	return 0;
}