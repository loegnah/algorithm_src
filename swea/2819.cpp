#include <cstdio>
#include <cstring>
using namespace std;

const int MX = 10000000;
const int N = 4;
const int LEN = 7;
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };

int board[N + 2][N + 2], count, nums[LEN];
bool isMade[MX];

int makeNum()
{
	int ret = nums[0];
	for (int i = 1; i < LEN; ++i) ret = ret * 10 + nums[i];
	return ret;
}

void fullSearch(int y, int x, int k)
{
	if (y < 0 || y >= N || x < 0 || x >= N) return;

	nums[k] = board[y][x];

	if (k == LEN - 1) {
		int num = makeNum();
		if (!isMade[num]) {
			isMade[num] = true;
			count++;
		}
		return;
	}

	for (int i = 0; i < 4; ++i) fullSearch(y + dy[i], x + dx[i], k + 1);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc)
	{
		memset(isMade, 0, sizeof isMade);

		for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x)
			scanf("%d", &board[y][x]);

		count = 0;
		for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x) {
			fullSearch(y, x, 0);
		}
		printf("#%d %d\n", tc, count);
	}
}