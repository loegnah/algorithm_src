#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX = 987654321;
const int W_MX = 12;
const int H_MX = 15;

int N, W, H;
vector<vector<int>> backupBoard, board;

void input()
{
	int tmp;
	scanf("%d %d %d", &N, &W, &H);
	board = vector<vector<int>>(H, vector<int>(W, 0));
	for (int y = 0; y < H; ++y) for (int x = 0; x < W; ++x) {
		scanf("%d", &tmp);
		board[y][x] = tmp;
	}
}

void boom(int y, int x)
{
	if (board[y][x] == 0) return;
	int power = board[y][x];
	board[y][x] = 0;
	for (int p = 1; p < power; ++p) {
		if (y - p >= 0) boom(y - p, x);
		if (x - p >= 0) boom(y, x - p);
		if (y + p < H) boom(y + p, x);
		if (x + p < W) boom(y, x + p);
	}
}

void downBlock()
{
	for (int x = 0; x < W; ++x) for (int y = H - 1; y >= 0; --y) {
		if (board[y][x] == 0) {
			int cy = y - 1;
			while (cy>=0 && board[cy][x] == 0) cy--;
			if (cy < 0) break;
			swap(board[y][x], board[cy][x]);
		}
	}
}

void printBlocks()
{
	printf("\n");
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) printf("%d ", board[y][x]);
		printf("\n");
	}
}

int solve()
{
	int ans = MX;
	backupBoard.assign(board.begin(), board.end());
	for (int cs = 0; cs < pow(W,N); ++cs) {
		int curCs = cs, round = 0, cant = false;
		while (round++ < N) {
			int y = 0, x = curCs % W;
			while (y<H && !board[y][x]) y++;
			if(y<H) boom(y, x);
			curCs /= W;
			downBlock();
		}
		
		int count = 0;
		for (int y = 0; y < H; ++y) for (int x = 0; x < W; ++x) {
			if (board[y][x]) count++;
		}
		if (count < ans) ans = count;

		board.assign(backupBoard.begin(), backupBoard.end());
	}
	return ans;
}


int main()
{
	int T;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input();
		printf("#%d %d\n",tc,solve());
	}
}