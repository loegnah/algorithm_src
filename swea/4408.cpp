#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<pair<int, int> > vct;

void input_init()
{
	int tmp,st, en;
	vct.clear();

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &st, &en);
		st = (st + 1) / 2;
		en = (en + 1) / 2;
		if (st > en) {
			tmp = st;
			st = en;
			en = tmp;
		}
		vct.push_back(make_pair(st, 0));
		vct.push_back(make_pair(en, 1));
	}
}

int solve()
{
	int cnt = 0, mx = 0;
	
	sort(vct.begin(), vct.end());
	for (auto cur : vct) {
		if (cur.second) cnt--;
		else {
			cnt++;
			if (cnt > mx) mx = cnt;
		}
	}
	return mx;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		printf("#%d %d\n", tc, solve());
	}
}