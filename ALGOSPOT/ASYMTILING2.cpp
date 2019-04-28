#include <iostream>
#include <cstring>
using namespace std;

int cache[101], cache2[101];
int N;
int MOD = 1000000007;

int tiling(int cur);
int asym2(int w);

int main()
{
	int C;

	scanf("%d", &C);
	for (int i = 0; i < C; ++i) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		scanf("%d", &N);
		printf("%d\n", asym2(N));
	}
}

int asym2(int w)
{
	if (w <= 2) return 0;

	int &ret = cache2[w];
	if (ret != -1) return ret;

	ret = asym2(w - 2) % MOD;
	ret = (ret + asym2(w - 4)) % MOD;
	ret = (ret + tiling(w - 3)) % MOD;
	ret = (ret + tiling(w - 3)) % MOD;
	return ret;
}

int tiling(int cur)
{
	if (cur <= 1) return 1;

	int &ret = cache[cur];
	if (ret != -1) return ret;

	ret = (tiling(cur - 1) + tiling(cur - 2)) % MOD;
	return ret;
}