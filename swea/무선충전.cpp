#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

typedef pair<int, int> paii;

const int CY[5] = { 0,-1,0,1,0 };
const int CX[5] = { 0,0,1,0,-1 };

int M, N, moveA[103], moveB[103];
vector<paii> board[11][11];

void pointing(int y, int x, int c, int p, int idx) 
{
	int cy;
	for (int i = 0; i <= c && y - i > 0; ++i) {
		cy = y - i;
		for (int j = 0; j <= c - i && x + j <= 10; ++j) board[cy][x + j].push_back(paii(p,idx));
		for (int j = 1; j <= c - i && x - j > 0; ++j) board[cy][x - j].push_back(paii(p,idx));
	}
	for (int i = 1; i <= c && y + i <= 10; ++i) {
		cy = y + i;
		for (int j = 0; j <= c - i && x + j <= 10; ++j) board[cy][x + j].push_back(paii(p,idx));
		for (int j = 1; j <= c - i && x - j > 0; ++j) board[cy][x - j].push_back(paii(p,idx));
	}
}

void input_init()
{
	int y, x, c, p;

	for (int y = 1; y <= 10; ++y) for (int x = 1; x <= 10; ++x) board[y][x].clear();

	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; ++i) scanf("%d", moveA + i);
	for (int i = 0; i < M; ++i) scanf("%d", moveB + i);
	for (int i = 0; i < N; ++i) {
		scanf("%d %d %d %d", &x, &y, &c, &p);
		pointing(y, x, c, p, i);
	}
	for (int y = 1; y <= 10; ++y) for (int x = 1; x <= 10; ++x)
		sort(board[y][x].begin(), board[y][x].end(), greater<paii>());
}

int maxChargeSum(vector<paii>& av, vector<paii>& bv)
{
	if (av.empty() && bv.empty()) return 0;
	if (av.empty() || bv.empty()) {
		if (av.empty()) return bv[0].first;
		return av[0].first;
	}

	int ret = av[0].first, bcA = av[0].second, bcB = bv[0].second;
	if (bcA != bcB) return av[0].first + bv[0].first;
	if (av.size() > 1) ret = av[1].first + bv[0].first;
	if (bv.size() > 1) ret = max(ret, av[0].first + bv[1].first);
	return ret;
}

int solve()
{
	int ay = 1, ax = 1, by = 10, bx = 10;
	int ans = 0;

	for (int tm = 0; tm <= M; ++tm) {
		ans += maxChargeSum(board[ay][ax], board[by][bx]);

		ay += CY[moveA[tm]]; ax += CX[moveA[tm]];
		by += CY[moveB[tm]]; bx += CX[moveB[tm]];
	}

	return ans;
}

int main()
{
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		printf("#%d %d\n", tc, solve());
	}
}