#include <iostream>
#include <cstring>
using namespace std;

int cache[101];
int N;
int MOD = 1000000007;

int tiling(int cur);
int asym();

int main()
{
	int C;

	scanf("%d", &C);
	for (int i = 0; i < C; ++i) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		printf("%d\n", asym());
	}
}

int asym()
{
	int totRet = tiling(N);

	totRet = (totRet - tiling(N / 2) + MOD) % MOD;
	if (N % 2 == 0) totRet = (totRet - tiling(N / 2 - 1) + MOD) % MOD;
	
	return totRet;
}

int tiling(int cur)
{
	if (cur <= 1) return 1;

	int &ret = cache[cur];
	if (ret != -1) return ret;

	ret = (tiling(cur - 1) + tiling(cur - 2)) % MOD;
	return ret;
}