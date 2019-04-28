#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int L[5001], M[5001], G[5001];

int moreThanK(int endPoint)
{
	int numSign = 0;
	for (int n = 0; n < N; ++n) {
		if (endPoint > L[n] - M[n])
			numSign += (min(endPoint, L[n]) - (L[n] - M[n])) / G[n] + 1;
	}
	return numSign >= K;
}

int KthSign()
{
	int lo = 0, hi = 8030000;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (moreThanK(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

int main()
{
	int T;

	scanf("%d", &T);
	for (int testcase = 0; testcase < T; ++testcase)
	{
		scanf("%d %d", &N, &K);
		for (int n = 0; n < N; ++n)
			scanf("%d %d %d", L + n, M + n, G + n);

		int ans = KthSign();
		printf("%d\n", ans);
	}
}
