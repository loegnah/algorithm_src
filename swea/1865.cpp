#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int MX_N = 16;

int n;
double prob[MX_N][MX_N], cache[1 << MX_N][MX_N], ans;

double _dmax(double a, double b) { return a>b ? a : b; }

void input()
{
	double tmp;
	scanf("%d", &n);
	for (int i = 0; i<n; ++i) for (int j = 0; j<n; ++j) {
		scanf("%lf", &tmp);
		prob[i][j] = tmp / 100.0;
	}
	memset(cache, 0, sizeof cache);
}

double dp(int choice, int cur)
{
	if (cur == n) return 1.0;

	double& ret = cache[choice][cur];
	if (ret != 0.0) return ret;

	ret = -1.0;
	for (int i = 0; i<n; ++i) {
		if (choice & (1 << i)) continue;
		ret = _dmax(ret, prob[cur][i] * dp((choice | (1 << i)), cur + 1));
	}
	return ret;
}

void solve()
{
	int tmp;
	ans = dp(0, 0);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		input();
		solve();

		printf("#%d %.6lf\n", tc, ans*100.0);
	}
}
