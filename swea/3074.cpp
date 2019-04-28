#include <cstdio>
#include <algorithm>
using namespace std;

const int MX_N = 100005;

long long N, M, tk[MX_N], mxTime;

void input_init()
{
	scanf("%lld %lld", &N, &M);
	mxTime = -1;
	for (int i = 0; i < N; ++i) {
		scanf("%lld", tk + i);
		if (mxTime < tk[i]) mxTime = tk[i];
	}
	sort(tk, tk + N);
}

long long solve()
{
	long long lo = 0, hi = mxTime*M;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;

		long long tot = 0;
		for (int i = 0; i < N; ++i) tot += (mid / tk[i]);

		if (tot < M) lo = mid;
		else hi = mid;
	}
	return hi;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		printf("#%d %lld\n", tc, solve());
	}
}