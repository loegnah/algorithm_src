#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXD = 100000, MAXN = 100000;
const int MOD = 20091101;

int N, K;
int D[MAXN + 2];
int bb[MAXN + 2];
int sameBb[MAXD + 1];

int solve1()
{
	int ret = sameBb[0];

	for (int i = 0; i < K; ++i) {
		if (sameBb[i]) ret = (ret + (sameBb[i] * (sameBb[i] - 1) / 2 )) % MOD;
	}
	return ret;
}

int solve2()
{
	vector<int> ret(N + 1, 0);
	vector<int> pre(K + 1, 0);

	int idx;
	for (int i = 1; i <= N; ++i) {
		ret[i] = ret[i - 1];
		idx = pre[bb[i]];
		if (bb[i] == 0) ret[i] = ret[i] + 1;
		else if (idx != 0) ret[i] = max(ret[i], ret[idx] + 1);
		pre[bb[i]] = i;
	}
	return ret[N];
}

void booBunMod()
{
	bb[0] = 0;
	for (int i = 1; i <= N; ++i) {
		bb[i] = (bb[i - 1] + D[i]) % K;
		++sameBb[bb[i]];
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		memset(sameBb, 0, sizeof(sameBb));

		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; ++i)
			scanf("%d", D + i);
		booBunMod();
		int ans1 = solve1();
		int ans2 = solve2();
		printf("%d %d\n", ans1, ans2);
	}
}