// 삼성 오후 2번
// acmicpc 16236

#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

const int CY[4] = { -1,0,0,1 };
const int CX[4] = { 0,-1,1,0 };

int N, board[23][23], init_y, init_x;
int cur_size, cur_ate;
bool isChecked[23][23];

void input_init()
{
	int ipt;
	scanf("%d", &N);
	for (int y = 0; y < N; ++y) for (int x = 0; x < N; ++x) {
		scanf("%d", &ipt);
		board[y][x] = ipt;
		if (ipt == 9) { init_y = y; init_x = x; }
	}
	cur_size = 2;
	cur_ate = 0;
}

int bfs()
{
	int ty, tx, y, x, d, yy = 500, xx = 500, dd = 500;
	bool isFind = false;
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
		isChecked[i][j] = false;

	queue<pair<int, int> > qu;
	qu.push(make_pair(init_y * 100 + init_x, 0));
	isChecked[init_y][init_x] = true;

	while (!qu.empty()) {
		ty = qu.front().first / 100;
		tx = qu.front().first % 100;
		d = qu.front().second;
		qu.pop();

		if (dd < d) break;

		for (int i = 0; i < 4; ++i) {
			y = ty + CY[i];
			x = tx + CX[i];

			if (y < 0 || y >= N || x < 0 || x >= N || isChecked[y][x]) continue;
			isChecked[y][x] = true;
			
			int tmp = board[y][x];
			if (tmp == 0 || tmp == cur_size) {
				if (!isFind) qu.push(make_pair(y * 100 + x, d + 1));
			}
			else if (tmp < cur_size) {
				isFind = true;
				dd = d;
				if (y < yy || (y == yy&&x < xx)) {
					yy = y;
					xx = x;
				}
			}
		}
	}
	if(!isFind) return -1;
	board[init_y][init_x] = 0;
	board[yy][xx] = 9;
	init_y = yy;
	init_x = xx;
	return dd + 1;
}

int solve()
{
	int ans = 0, ret;

	while (true) {
		ret = bfs();
		if (ret == -1) break;
		ans += ret;
		cur_ate++;
		if (cur_ate == cur_size) {
			cur_ate = 0;
			cur_size++;
		}
	}
	return ans;
}

int main()
{
	/*
	int t;
	scanf("%d", &t);
	while (t--) {
		input_init();
		printf("%d\n", solve());
	} */
	input_init();
	printf("%d\n", solve());
}