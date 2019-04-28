#include <iostream>
#include <cstring>
using namespace std;

int N;
int cache[101];
int MOD = 1000000007;

int tiling(int cur)
{
	if (cur <= 1) return 1;
	
	int &ret = cache[cur];
	if (ret != -1) return ret;

	ret = (tiling(cur - 1) + tiling(cur - 2)) % MOD;
	return ret;
}

int main()
{
	int C;
	
	scanf("%d", &C);
	for (int i = 0; i < C; ++i) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		printf("%d\n",tiling(N));
	}
}