#include <iostream>
#include <cstring>
#include <limits>
#include <algorithm>
using namespace std;

long long MININF = numeric_limits<long long>::min();
int cache[101][101];
int A[101], B[101];
int n, m;

int JLIS(int a, int b)
{
	int& ret = cache[a+1][b+1];
	if (ret != -1) return ret;
	ret = 2;

	long long aMx = (a == -1 ? MININF : A[a]);
	long long bMx = (b == -1 ? MININF : B[b]);
	long long mx = max(aMx, bMx);

	for (int ai = a + 1; ai < n; ++ai) {
		if (mx < A[ai]) ret = max(ret, JLIS(ai, b) + 1);
	}
	for (int bi = b + 1; bi < m; ++bi) {
		if (mx < B[bi]) ret = max(ret, JLIS(a, bi) + 1);
	}
	return ret;
}

int main()
{
	int c, ans;

	cin >> c;
	while (c-- > 0) {
		memset(cache, -1, sizeof(cache));
		ans = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
		for (int i = 0; i < m; ++i) scanf("%d", &B[i]);

		ans = JLIS(-1, -1) - 2;
		cout << ans << endl;
	}
}
