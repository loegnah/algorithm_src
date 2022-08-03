#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int arr[10003];
int cache[10003][3];

int dp(int k,int p) {
	if (k >= n) return 0;
	int &ret = cache[k][p];
	if (ret != 0) return ret;

	if (p == 2) return ret = dp(k + 1, 0);
	return ret = max(dp(k + 1, p + 1) + arr[k], dp(k + 1, 0));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);
	printf("%d\n", dp(0, 0));
	
}