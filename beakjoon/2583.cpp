#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int ld[103][2], rh[103][2];
int board[103][103] = { 0 };
int cy[4] = { -1,0,1,0 };
int cx[4] = { 0,1,0,-1 };
int ret = 0;

void dfs(int y, int x)
{
	ret++;
	board[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + cy[i], nx = x + cx[i];
		if (!board[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	int ct = 0;
	vector<int> ans;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d %d %d %d", &ld[i][0], &ld[i][1], &rh[i][0], &rh[i][1]);
		for (int y = ld[i][1] + 1; y < rh[i][1] + 1; ++y)
			for (int x = ld[i][0] + 1; x < rh[i][0] + 1; ++x)
				board[y][x] = 1;
	}
	for (int i = 0; i < N+2; ++i)
		board[i][0] = board[i][M + 1] = 1;
	for (int i = 0; i < M+2; ++i)
		board[0][i] = board[N+1][i] = 1;

	for (int y = 1; y < N + 1; ++y)
		for (int x = 1; x < M + 1; ++x)
			if (!board[y][x]) {
				ret = 0;
				ct++;
				dfs(y, x);
				ans.push_back(ret);
			}
	sort(ans.begin(), ans.end());
	printf("%d\n", ct);
	for (int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
}