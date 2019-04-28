#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int R[1001], C[1001];

bool canMake(double x)
{
	vector<double> asc;
	for (int n = 0; n < N; ++n)
		asc.push_back(x*C[n] - R[n]);
	sort(asc.begin(), asc.end());

	double minSum = 0;
	for (int k = 0; k < K; ++k)
		minSum += asc[N-k-1];
	return minSum >= 0;
}

double minRank()
{
	double lo = -1e-9;
	double hi = 1;

	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2.0;
		if (canMake(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d %d", &N, &K);
		for (int n = 0; n < N; ++n)
			scanf("%d %d", R + n, C + n);
		double ans = minRank();
		printf("%.10lf\n", ans);
	}
}