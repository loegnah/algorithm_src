#include <cstdio>
#include <cstring>
using namespace std;

const char A = 'a';

int L, K, iptLen;
int inCost[26], outCost[26], cache[2003][2003];
char ipt[2003];

inline int _min(int a, int b) {
	return a < b ? a : b;
}

void input_init()
{
	memset(cache, -1, sizeof(cache));

	scanf("%d %d", &L, &K);
	scanf("%s", ipt);
	iptLen = (int)strlen(ipt);
	for (int i = 0; i < K; ++i) scanf("%d %d", inCost + i, outCost + i);
}

int dp(int left, int right)
{
	if (left >= right) return 0;

	int &ret = cache[left][right];
	if (ret != -1) return ret;

	int lf_ch = ipt[left]-A, rt_ch = ipt[right]-A;
	
	if (lf_ch == rt_ch) return ret = dp(left + 1, right - 1);
	
	ret = dp(left + 1, right) + _min(inCost[lf_ch], outCost[lf_ch]);
	ret = _min(ret, dp(left, right - 1) + _min(inCost[rt_ch], outCost[rt_ch]));
	return ret;
}


int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		printf("#%d %d\n", tc, dp(0, iptLen - 1));
	}
}