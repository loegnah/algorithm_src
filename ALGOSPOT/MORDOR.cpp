#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Level {
public:
	int mx;
	int mn;
};

const int MX = numeric_limits<int>::max();
const int MN = numeric_limits<int>::min();
int N, Q;
int pan[100001];
Level level[400004];



Level initCalc(int left, int right, int n)
{
	Level& ret = level[n];
	if (left == right) {
		ret.mx = pan[left];
		ret.mn = pan[right];
	} 
	else {
		int mid = (left + right) / 2;
		Level tmp1 = initCalc(left, mid, n * 2 + 1);
		Level tmp2 = initCalc(mid + 1, right, n * 2 + 2);
		ret.mx = max(tmp1.mx, tmp2.mx);
		ret.mn = min(tmp1.mn, tmp2.mn);
	}
	return ret;
}

Level mxmn(int left, int right, int n, int start, int end)
{
	if (start <= left && right <= end)
		return level[n];
	
	Level ret;
	if (right < start || end < left) {
		ret.mx = MN;
		ret.mn = MX;
	}
	else {
		int mid = (left + right) / 2;
		Level tmp1 = mxmn(left, mid, n * 2 + 1, start, end);
		Level tmp2 = mxmn(mid + 1, right, n * 2 + 2, start, end);
		ret.mx = max(tmp1.mx, tmp2.mx);
		ret.mn = min(tmp1.mn, tmp2.mn);
	}
	return ret;
}

void solve()
{
	int start, end;
	initCalc(0, N - 1, 0);
	
	Level ans;
	for (int q = 0; q < Q; ++q) {
		scanf("%d %d", &start, &end);
		ans = mxmn(0, N - 1, 0, start, end);
		printf("%d\n", ans.mx - ans.mn);
	}
}

int main()
{
	int T;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &Q);
		for (int i = 0; i < N; ++i)
			scanf("%d", pan + i);
		solve();
	}
}