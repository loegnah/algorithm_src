#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef priority_queue<pair<int, int>> pqpii;

const int SIZE = 200;
const int INACTIVE = 1, ACTIVE = 2;
const int TW = 12; // Åõ¿¤ºì TW!
const int CY[4] = { 1,0,-1,0 };
const int CX[4] = { 0,1,0,-1 };

int N, M, K;
int board[SIZE * 2][SIZE * 2];
vector<pqpii> qu;
vector<queue<int>> dieQu;

void input_init()
{
	int hp;
	qu = vector<pqpii>(TW, pqpii());
	dieQu = vector<queue<int>>(TW, queue<int>());
	memset(board, 0, sizeof(board));
	scanf("%d %d %d", &N, &M, &K);
	for (int y = SIZE; y < N + SIZE; ++y)
		for (int x = SIZE; x < M + SIZE; ++x) {
			scanf("%d", &hp);
			board[y][x] = hp;
			if (hp > 0) qu[hp + 1].push(make_pair(hp, y * 1000 + x));
		}
}

void breed(int y, int x, int hp, int tm)
{
	for (int i = 0; i < 4; ++i) {
		int ny = y + CY[i], nx = x + CX[i];
		if (board[ny][nx] == 0) {
			board[ny][nx] = hp;
			qu[(tm + hp + 1) % TW].push(make_pair(hp, ny*1000+nx));
		}
	}
	if (hp > 1) dieQu[(tm + hp - 1) % TW].push(y * 1000 + x);
	else board[y][x] = -1;
}

// µð¹ö±×¿ë
void printBoard()
{
	printf("\n\n");
	for (int y = SIZE - 5; y <= SIZE + 15; ++y) {
		for (int x = SIZE - 5; x <= SIZE + 15; ++x) 
			printf("%2d ", board[y][x]);
		printf("\n");
	}
}

int solve()
{
	int y, x, hp;
	pair<int, int> tmp;
	for (int tm = 1; tm <= K; ++tm) {
		int cur = tm%TW;
		while (!qu[cur].empty()) {
			tmp = qu[cur].top(); qu[cur].pop();
			y = tmp.second / 1000;
			x = tmp.second % 1000;
			hp = tmp.first;
			breed(y, x, hp, tm);
		}
		while (!dieQu[cur].empty()) {
			y = dieQu[cur].front() / 1000;
			x = dieQu[cur].front() % 1000;
			board[y][x] = -1;
			dieQu[cur].pop();
		}
		//printBoard();
	}
	
	int ans = 0;
	for (int y = 0; y < SIZE * 2; ++y) 
		for (int x = 0; x < SIZE * 2; ++x) {
			if (board[y][x] > 0) ++ans;
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
