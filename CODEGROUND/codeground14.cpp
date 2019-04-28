/* 거의 완전히 베낌
	코드보고 이해하기 엄청 어려웠지만
	배울점이 아주 많음 */


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000005, MIN = -1;

struct point {
	int a,b;
	bool operator<(const point& k) const {
		return this->a + this->b < k.a + k.b;
	}
};

struct mxn {
	int mx, mn;
};
int N;
vector<point> x, y;

void point_swap(point& p) {
	int tmp = p.a;
	p.a = p.b;
	p.b = tmp;
}

void input()
{
	scanf("%d", &N);
	x = vector<point>(N);
	y = vector<point>(N);
	
	for (int i = 0; i < N; ++i) {
		scanf("%d %d %d %d", &x[i].a, &y[i].a, &x[i].b, &y[i].b);
		if (x[i].a > x[i].b) point_swap(x[i]);
		if (y[i].a > y[i].b) point_swap(y[i]);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
}

int min_dist_point(vector<point>& p)
{
	vector<mxn> lf(N+1), rt(N+1);
	lf[0].mx = rt[N].mx = MIN;
	lf[0].mn = rt[N].mn = MAX;

	for (int i = N - 1; i >= 0; --i) {
		rt[i].mx = max(rt[i + 1].mx, p[i].a);
		rt[i].mn = min(rt[i + 1].mn, p[i].a);
	}
	for (int i = 1; i <= N; ++i) {
		lf[i].mx = max(lf[i - 1].mx, p[i - 1].b);
		lf[i].mn = min(lf[i - 1].mn, p[i - 1].b);
	}
	int ret = MAX;
	for (int i = 0; i <= N; ++i) {
		ret = min(ret, max(rt[i].mx, lf[i].mx) - min(rt[i].mn, lf[i].mn));
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input();
		int x_dist = min_dist_point(x);
		int y_dist = min_dist_point(y);
		int ans = max(x_dist, y_dist);
		
		printf("Case #%d\n", tc);
		if (ans % 2) printf("%d.5\n", ans / 2);
		else printf("%d\n", ans / 2);
	}
}