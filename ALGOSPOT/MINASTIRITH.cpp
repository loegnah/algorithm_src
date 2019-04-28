#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

const double PI = 3.1415926535897932384;
pair<double, double> ang[101];
int N;

void convertAng(double y, double x, double r, int n)
{
	double midAng = fmod((atan2(y, x) * 360 / (2 * PI)) + 360, 360.0);
	double difAng = asin(r / 16.0) *360 / (2*PI) * 2;
	ang[n].first = midAng - difAng;
	ang[n].second = midAng + difAng;
}

int remainCover(double st, double en)
{
	int ret = 0, idx = 0;
	while (st < en)
	{
		double maxEnd = 0;
		while (idx < N && ang[idx].first <= st) {
			maxEnd = max(maxEnd, ang[idx].second);
			++idx;
		}
		if (maxEnd <= st) return 999;
		st = maxEnd;
		++ret;
	}
	return ret;
}

int startCover()
{
	int ret = 999;
	double st, en;
	sort(ang, ang + N);
	for (int i = 0; i < N; ++i) 
		if (ang[i].first <= 0 || ang[i].second >= 360.0) {
			st = fmod(ang[i].second, 360.0);
			en = fmod(ang[i].first + 360.0, 360.0);
			ret = min(ret, 1 + remainCover(st,en));
		}
	return ret;
}

int main()
{
	int C, ans;
	scanf("%d", &C);
	for (int test = 0; test < C; ++test) {
		scanf("%d", &N);

		double y, x, r;
		bool ck = false;
		for (int n = 0; n < N; ++n) {
			scanf("%lf %lf %lf", &y, &x, &r);
			if (r >= 16.0) {
				ck = true;
				break;
			}
			convertAng(y, x, r, n);
		}
		if (ck) {
			printf("1\n");
			continue;
		}
		ans = startCover();
		if (ans > 100) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}
}