#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

const int CY[2] = { 1,0 }, CX[2] = { 0,1 };
int N, X, h[21][21];

bool check(int y, int x, int dir)
{
	vector<pair<int, int> > v;
	int yy = y, xx = x;
	int tmpH = h[y][x];
	int tmpLen = 0;

	for (int i = 0; i < N; ++i) {
		int curH = h[yy][xx];
		if (tmpH != curH) {
			if (tmpH - curH < -1 || tmpH - curH > 1) return false;
			v.push_back(make_pair(tmpH, tmpLen));
			tmpLen = 0;
			tmpH = curH;
		}
		++tmpLen;
		yy += CY[dir];
		xx += CX[dir];
	}
	if (tmpLen >= 1) v.push_back(make_pair(tmpH, tmpLen));
	
	int preUsed = 0;
	for (int i = 0; i + 1 < v.size(); ++i) {
		if (v[i].first < v[i + 1].first) {
			if (v[i].second - preUsed < X) return false;
			preUsed = 0;
		}
		else {
			if (v[i + 1].second < X) return false;
			preUsed = X;
		}
	}
	return true;
}

int main()
{
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d", &N, &X);
		for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x)
			scanf("%d", &h[y][x]);

		int ans = 0;
		for (int y = 0; y < N; ++y) if (check(y, 0, 1)) ++ans;
		for (int x = 0; x < N; ++x) if (check(0, x, 0)) ++ans;
		printf("#%d %d\n", tc, ans);
	}
}