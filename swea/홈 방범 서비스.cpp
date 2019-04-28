#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int N, M, costs[42];
vector<pair<int, int>> homes;

int _abs(int a) { return a > 0 ? a : -a; }

void pre_calc()
{
	for (int k = 1; k <= 40; ++k) {
		costs[k] = k*k + (k - 1)*(k - 1);
	}
}

void input_init()
{
	int ipt;
	scanf("%d %d", &N, &M);

	homes.clear();
	for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x) {
		scanf("%d", &ipt);
		if (ipt) homes.push_back(make_pair(y,x));
	}
}

int dist_calc()
{
	int ret = 0;
	int inArea[41] = { 0 };
	for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x) {
		memset(inArea, 0, sizeof(inArea));
		for (pair<int, int> yx : homes) {
			int d = _abs(y - yx.first) + _abs(x - yx.second) + 1;
			inArea[d]++;
		}
		
		int homeCount = 0;
		for (int k = 1; k <= 40; ++k) {
			homeCount += inArea[k];
			if (homeCount*M - costs[k] >= 0 && ret < homeCount)
				ret = homeCount;
		}
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	pre_calc();
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		dist_calc();
		printf("#%d %d\n", tc, dist_calc());
	}
}