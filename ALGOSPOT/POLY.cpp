#include <iostream>
#include <cstring>
using namespace std;

int cache[101][101];
int N;
int MOD = 10000000;

int poly(int cur, int remain);
int tot();

int main()
{
	int C;

	scanf("%d", &C);
	for (int test = 0; test < C; ++test) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);

		printf("%d\n", tot());
	}
}

int tot()
{
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans = (ans + poly(i, N - i)) % MOD;
	return ans;
}

int poly(int cur, int remain)
{
	if (remain == 0) return 1;

	int &ret = cache[cur][remain];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = 1; remain - next >= 0; ++next) {
		ret = ret + (poly(next, remain - next)*(cur + next - 1));
		ret %= MOD;
	}
	return ret;
}
