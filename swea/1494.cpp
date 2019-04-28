#include <cstdio>
using namespace std;

struct Point {
	int y, x;
};

const long long MX = 80000000000LL;

int n, check[20];
long long ans;
Point pt[20];

void calc_vct()
{
	long long x=0,y=0;
	for (int i = 0; i < n; ++i) {
		x += check[i] * pt[i].x;
		y += check[i] * pt[i].y;
	}
	long long tot = x*x + y*y;
	if (tot < ans) ans = tot;
}

void solve(int idx, int rmn)
{
	if (idx == n) calc_vct();
	else {
		if (rmn) {
			check[idx] = 1;
			solve(idx + 1, rmn - 1);
		}
		if (rmn < n - idx) {
			check[idx] = -1;
			solve(idx + 1, rmn);
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d %d", &pt[i].y, &pt[i].x);

		ans = MX;
		for (int i = 0; i < n; ++i) check[i] = 0;
		solve(0, n / 2);
		
		printf("#%d %lld\n", tc, ans);
	}
	
}