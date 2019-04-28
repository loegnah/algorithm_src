#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int T, M, C;
int coins[102];
int cache[102][5002];

int dp(int cn, int rms) // cn = coin number , rms = remain money
{
	if (rms == 0) return 1;
	if (cn == C || rms < 0) return 0;
	int& ret = cache[cn][rms];
	if (ret != -1) return ret;
	return ret = (dp(cn + 1, rms) + dp(cn, rms - coins[cn])) % MOD;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		memset(cache, -1, sizeof cache);
		scanf("%d %d", &M, &C);
		for (int i = 0; i<C; ++i) scanf("%d", coins + i);
		printf("%d\n", dp(0, M));
	}
}
