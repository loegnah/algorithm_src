#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int SIZE = 100000;

int N, M, fwTree[SIZE + 5];
vector<int> ans;

void _update(int idx, int num)
{
	while (idx <= N) {
		fwTree[idx] += num;
		idx += (idx & -idx);
	}
}

int _allSum(int idx)
{
	int ret = 0;
	while (idx > 0) {
		ret += fwTree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

int _sum(int st, int en)
{
	return _allSum(en) - _allSum(st - 1);
}

void input_init()
{
	int tmp;

	memset(fwTree, 0, sizeof fwTree);
	ans.clear();

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &tmp);
		_update(i, tmp);
	}
}

void solve()
{
	int c, a, b;

	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &c, &a, &b);
		if (c == 1) _update(a, b);
		else ans.push_back(_sum(a, b));
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		solve();

		printf("#%d", tc);
		for (int i = 0; i < ans.size(); ++i) printf(" %d", ans[i]);
		printf("\n");
	}
}