#include <cstdio>
#include <cstring>
using namespace std;

const int MX_N = 100005;

int n, child[MX_N];

int main()
{
	int T,num;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);
		memset(child, 0, sizeof child);

		int mxSqn = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d",&num);
			child[num] = child[num - 1] + 1;
			if (mxSqn < child[num]) mxSqn = child[num];
		}
		printf("#%d %d\n", tc, n-mxSqn);
	}
}