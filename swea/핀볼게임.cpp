#include <cstdio>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

const int UP = 0, RT = 1, DW = 2, LF = 3;
const int BLOCK[6][4] = {
	{0,},{DW,LF,RT,UP},{RT,LF,UP,DW},
	{LF,DW,UP,RT}, {DW,UP,LF,RT}, {DW,LF,UP,RT}
};
const int CY[4] = { -1,0,1,0 };
const int CX[4] = { 0,1,0,-1 };

int N, board[105][105];
vector<pair<int,int>> wormhole[12];
bool visited[105][105][4];

int _abs(int a) { return a > 0 ? a : -a; }

void input_init()
{
	int num;
	scanf("%d", &N);
	for (int i = 6; i <= 10; ++i) wormhole[i].clear();
	for (int y = 1; y <= N; ++y) for (int x = 1; x <= N; ++x) {
		scanf("%d", &num);
		board[y][x] = num;
		if (num >= 6) wormhole[num].push_back(make_pair(y, x));
	}
	for (int y = 1; y <= N; ++y) board[y][0] = board[y][N + 1] = 5;
	for (int x = 1; x <= N; ++x) board[0][x] = board[N + 1][x] = 5;
	memset(visited, 0, sizeof(visited));
}

int start(int sy, int sx, int sdir)
{
	int y = sy + CY[sdir], x = sx + CX[sdir], dir = sdir;
	int score = 0;
	visited[sy][sx][sdir] = true;
	while(true) {
		int cur = board[y][x];
		if (cur > 0 && cur < 6) {
			if (_abs(dir - BLOCK[cur][dir]) == 2)
				return score * 2 + 1;
			score++;
			dir = BLOCK[cur][dir];
			y += CY[dir]; 
			x += CX[dir];
		}
		else if (cur >= 6) {
			pair<int, int> wh1 = wormhole[cur][0];
			pair<int, int> wh2 = wormhole[cur][1];
			if (wh1.first == y && wh1.second == x) {
				y = wh2.first + CY[dir]; x = wh2.second + CX[dir];
			}
			else {
				y = wh1.first + CY[dir]; x = wh1.second + CX[dir];
			}
		}
		else if (cur == -1 || (y==sy && x==sx)) return score;
		else {
			visited[y][x][dir] = true;
			y += CY[dir]; 
			x += CX[dir];
		}
	}
	return -1;
}

int solve()
{
	int ans = 0;
	for (int y = 1; y <= N; ++y) for (int x = 1; x <= N; ++x)
		for (int dir = 0; dir < 4; ++dir) {
			if ((board[y][x] != 0) || visited[y][x][dir]) continue;
			int score = start(y, x, dir);
			if (ans < score) ans = score;
		}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		printf("#%d %d\n",tc,solve());
	}
}