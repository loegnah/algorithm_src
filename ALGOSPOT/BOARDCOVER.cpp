#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define PLUS 11
#define MINUS -11

int H, W;
vector<string> block(20);
const int coverType[4][3][2] = {
	{ { 0,0 },{ 0,1 },{ 1,0 } },
	{ { 0,0 },{ 0,1 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,-1 } }
};

bool Setting(vector<string>& blockkk, int y, int x, int type, int ck)
{
	int dy, dx;
	bool ret = true;
	for (int i = 0; i < 3; ++i) {
		dy = y + coverType[type][i][0];
		dx = x + coverType[type][i][1];
		if (dy < 0 || dy >= H || dx < 0 || dx >= W) ret = false;
		else if ((blockkk[dy][dx] += ck) < '#') ret = false;
	}
	return ret;
}

int Cover(vector<string>& blockk)
{
	int y = -1, x = -1;
	for (int dy = 0; dy < H; ++dy) {
		for (int dx = 0; dx < W; ++dx) {
			if (blockk[dy][dx] == '.') {
				y = dy;
				x = dx;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;

	for (int type = 0; type < 4; ++type) {
		if (Setting(blockk, y, x, type, MINUS)) {
			ret += Cover(blockk);
		}
		Setting(blockk, y, x, type, PLUS);
	}
	return ret;
}

int main()
{
	int C, ret;
	int noBlockNum;

	cin >> C;
	while (C-- > 0) {
		noBlockNum = 0;

		cin >> H >> W;
		for (int i = 0; i < H; ++i) cin >> block[i];

		// 빈블럭 3의배수 아니면 불가능
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (block[i][j] == '.') ++noBlockNum;
			}
		}
		if (noBlockNum % 3 != 0) {
			cout << "0" << endl;
			continue;
		}
		ret = Cover(block);
		cout << ret << endl;
	}
}
