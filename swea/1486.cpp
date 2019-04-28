#include <cstdio>
using namespace std;

const int MX = 987654321;

int t,n, b, h[20],ans, choice[20];

void calc_dif() {
	int tot = 0;
	for (int i = 0; i < n; ++i) if (choice[i]) 
		tot += h[i];
	if (b <= tot) ans = (tot - b < ans) ? (tot - b) : ans;
}

void solve(int cur) {
	if (cur == n) calc_dif();
	else {
		choice[cur] = 0;
		solve(cur + 1);
		choice[cur] = 1;
		solve(cur + 1);
	}
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		scanf("%d %d", &n, &b);
		for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
		
		ans = MX;
		solve(0);
		printf("#%d %d\n", tc, ans);
	}
}